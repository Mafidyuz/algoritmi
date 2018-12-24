#include "grafi_liste_adiacenza.h"
#include <time.h>

Graph gen(int n, float p){
    Graph g = graph_new(n);
    srand(time(NULL));
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n;j++) {
            float r = ((float)(rand()%1000)/1000);
            if(p>r && i!=j)
                graph_edgeinsert(g,i,j);
        }
    }
    return g;
}

int degree(Graph g, int v){
    Listnode l = g->A[v];
    int count = 0;
    while (l!=NULL){
        l = l->next;
        count++;
    }
    return count;
}

int path1(Graph g, int v, int w, int *aux){
    aux[v]=1;                                   //Segna il vertice v come visitato.
    for(Listnode l=g->A[v]; l; l=l->next)       //Se v e w sono adiacenti, allora esiste un cammino semplice.
        if(l->V==w)
            return 1;
    for(Listnode l=g->A[v]; l; l=l->next)       //Se v e w non sono adiacenti, allora esiste un cammino semplice se preso un vertice adiacente a v mai visitato in precedenza, esso ha un cammino semplice con w.
        if(!aux[l->V] && path1(g,l->V,w,aux))
                return 1;
    return 0;                                   //Se v e w non sono adiacenti e nessun vertice adiacente a v ha un cammino semplice con w, allora non esiste un cammino semplice tra v e w.
}

int path(Graph g, int v, int w){
    int *aux = calloc(g->n, sizeof(int));
    for(int i=0; i<g->n;i++)
        aux[i]=0;
    return path1(g,v,w,aux);
}

int ccc(Graph g){
    int *aux = calloc(g->n,sizeof(int));
    int counter = 0;
    if(!aux){
        fprintf(stderr, "Errore di allocazione\n");
        exit(-4);
    }
    for(int i=0; i<g->n; i++){
        if(!aux[i]) {
            counter++;
            dfs1(g,i,aux,0);
        }
    }
    free(aux);
    return counter;
}

void cc(Graph g, int v){
    int *aux = calloc(g->n,sizeof(int));
    if(!aux){
        fprintf(stderr, "Errore di allocazione\n");
        exit(-4);
    }
    printf("%d è fortemente connesso con i vertici ",v);
    dfs1(g,v,aux,1);
    printf("\n");
}

void span1(Graph g, int i, int *aux, int space){
    struct listnode *t;
    aux[i]= 1;
    for(t=g->A[i]; t; t = t->next){
        if(!aux[t->V]){
            for(int j=0; j<space;j++)
                printf("   ");
            printf("*%d\n",t->V);
            span1(g,t->V, aux,space+1);
        }
    }
}

void span(Graph g, int v) {
    int *aux = calloc(g->n,sizeof(int));
    if(!aux){
        fprintf(stderr, "Errore di allocazione\n");
        exit(-4);
    }
    printf("*%d\n",v);
    span1(g,v,aux,1);
    printf("\n");
}

int shortestpath(Graph g, int v, int w){
    int *dist = calloc(g->n, sizeof(int));
    if(!dist){
        fprintf(stderr, "Errore di allocazione\n");
        exit(-4);
    }
    for(int i=0; i<g->n; i++)
        dist[i]=-1;
    dist[v]=0;
    Queue q = createqueue();
    q = enqueue(q,v);
    while(q){
        int i = dequeue(&q);
        for(Listnode t=g->A[i]; t; t=t->next){
            if(dist[t->V]==-1){
                q=enqueue(q,t->V);
                dist[t->V]=dist[i]+1;
            }
        }
    }
    queue_destroy(&q);
    return dist[w];
}

int twocolor1(Graph g, int i, int *aux, int *color, int last_color){
    aux[i]=1;
    last_color=!last_color;
    for(Listnode t=g->A[i]; t; t = t->next){
        if(!aux[t->V]){
            color[t->V]=last_color;
            if (!twocolor1(g,t->V, aux, color,last_color))
                return 0;
        }
        else if (color[t->V]==color[i])
            return 0;
    }
    return 1;
}

int twocolor(Graph g){
    int *aux = calloc(g->n, sizeof(int));
    int *color = calloc(g->n,sizeof(int));
    if(!(color && aux)){
        fprintf(stderr, "Errore di allocazione\n");
        exit(-4);
    }
    for(int i=0; i<g->n; i++)
        color[i]=-1;
    for(int i=0; i<g->n; i++){
        if(!aux[i]){
            color[i]=0;
            if (!twocolor1(g,i,aux,color,0))
                return 0;
        }
    }
    return 1;
}

int oddcycles(Graph g){
    return !twocolor(g);
}

int main(){
    Graph g = gen(10,0.2);
    graph_print(g);
    int v = 0;
    int w = 3;
    printf("Il grado del vertice %d è %d.\n",v,degree(g,v));
    if(path(g,v,w))
        printf("Cammino il cammino più corto tra %d e %d è lungo %d.\n",v,w,shortestpath(g,v,w));
    else
        printf("Non esiste un cammino da %d a %d.\n",v,w);
    printf("Il numero di componenti connesse del grafo è %d.\n",ccc(g));
    cc(g,v);
    if(twocolor(g))
        printf("Il grafo è bicolorabile.\n");
    else
        printf("Il grafo non è bicolorabile.\n");
    if(oddcycles(g))
        printf("Il grafo ha cicli dispari.\n");
    else
        printf("Il grafo non ha cicli dispari.\n");
    printf("Lo spanning tree con radice %d è\n",v);
    span(g,v);
    return 0;
}
