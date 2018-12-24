#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct listnode {
    struct listnode *next;
    int V;
};

typedef struct listnode *Listnode;


struct graph {
    int n, m;
    struct listnode **A;
};

typedef struct graph *Graph;

Graph graph_new(int n){
    Graph g = malloc(sizeof(Graph));
    g->n = n;
    g->m = 0;
    g->A = malloc(sizeof(struct listnode*)*n);
    return g;
}

void graph_destroy(Graph g){
    if (g){
        for(int i=0; i<g->n; i++)
            free(g->A[i]);
        free(g->A);
    }
}

void graph_edgeinsert(Graph g, int v, int w){
    struct listnode *l1 = malloc(sizeof(struct listnode));
    l1->V = w;
    l1->next = g->A[v];
    g->A[v] = l1;
    struct listnode *l2 = malloc(sizeof(struct listnode));
    l2->V = v;
    l2->next = g->A[w];
    g->A[w] = l2;
    g->m++;
}

Graph graph_read(void) {
    int n;
    printf("Inserire numero di vertici: ");
    scanf("%d",&n);
    Graph g = graph_new(n);
    int v,w;
    while(v!=-1 && w!=-1){
        printf("Inserire arco (v,w): ");
        scanf("%d %d",&v,&w);
        if (v!=-1 && w!=-1)
            graph_edgeinsert(g,v,w);
    }
    return g;
}

void graph_print(Graph g) {
    for(int i=0; i<g->n; i++){
        printf("%d -> ",i);
        struct listnode *next = g->A[i];
        while(next != NULL){
            printf("%d, ",next->V);
            if(next)
                next = next->next;
        }
        printf("\n");
    }
}

void dfs1(Graph g, int i, int *aux, int print){
    struct listnode *t;
    aux[i]= 1;
    for(t=g->A[i]; t; t = t->next){
        if(!aux[t->V]){
            if(print)
                printf("%d, ",t->V);
            dfs1(g,t->V, aux,print);
        }
    }
}

void dfs(Graph g){
    int *aux = calloc(g->n,sizeof(int));
    if(!aux){
        fprintf(stderr, "Errore di allocazione\n");
        exit(-4);
    }
    for(int i=0; i<g->n; i++){
        if(!aux[i]) {
            printf("\n%d, ",i);
            dfs1(g,i,aux,1);
        }
    }
    printf("\n");
    free(aux);
}

void bfs1(Graph g, int i, int *aux){
    Queue q = createqueue();
    q = enqueue(q,i);
    while(q){
        i=dequeue(&q);
        aux[i] = 1;
        for(Listnode t=g->A[i]; t; t=t->next){
            if(!aux[t->V]) {
                q=enqueue(q,t->V);
                printf("%d, ",t->V);
                aux[t->V] = 1;
            }
        }
    }
    queue_destroy(&q);
}

void bfs(Graph g){
    int *aux = calloc(g->n, sizeof(int));
    if(!aux){
        fprintf(stderr, "Errore di allocazione\n");
        exit(-4);
    }
    for(int i=0; i<g->n; i++){
        if(!aux[i]){
            printf("\n%d, ",i);
            bfs1(g,i,aux);
        }
    }
    printf("\n");
    free(aux);
}
