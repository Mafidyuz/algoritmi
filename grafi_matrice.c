#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct graph {
    int n, m;
    int **A;
};

typedef struct graph *Graph;

Graph graph_new(int n){
    Graph g = malloc(sizeof(Graph));
    g->n = n;
    g->m = 0;
    g->A = malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
        g->A[i] = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            g->A[i][j]=0;
    return g;
}

void graph_destroy(Graph g) {
    if (g){
        for(int i=0; i<g->n; i++)
            free(g->A[i]);
        free(g->A);
    }
}

void graph_edgeinsert(Graph g, int v, int w){
    g->A[v][w] = 1;
    g->A[w][v] = 1;
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
        for(int j=0;j<g->n;j++){
            if (g->A[i][j])
                printf("%d, ",j);
        }
        printf("\n");
    }
}

void dfs1(Graph g, int i, int *aux){
    printf("%d, ",i);
    aux[i]=1;
    for(int j=0;j<g->n;j++)
        if(!aux[j] && g->A[i][j]==1)
            dfs1(g,j,aux);
}

void dfs(Graph g){
    int *aux = calloc(g->n,sizeof(int));
    if(!aux){
        fprintf(stderr, "Errore di allocazione\n");
        exit(-4);
    }
    for(int i=0; i<g->n; i++)
        if(!aux[i]) {
            dfs1(g,i,aux);
            printf("\n");
        }
    free(aux);
}

void bfs1(Graph g, int i, int *aux){
    Queue q = createqueue();
    q = enqueue(q,i);
    while(q){
        int i=dequeue(&q);
        aux[i] = 1;
        for(int j=0; j<g->n; j++){
            if(!aux[j]&&g->A[i][j]==1){
                q=enqueue(q,j);
                printf("%d, ",j);
                aux[j]=1;
            }
        }
    }
}

void bfs(Graph g){
    int *aux = calloc(g->n,sizeof(int));
    if(!aux){
        fprintf(stderr, "Errore di allocazione\n");
        exit(-4);
    }
    for(int i=0; i<g->n; i++){
        if(!aux[i]) {
            printf("\n%d, ",i);
            bfs1(g,i,aux);
        }
    }
    printf("\n");
    free(aux);
}


int main(){
    Graph g = graph_read();
    bfs(g);
    return 0;
}
