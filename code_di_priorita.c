#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define N 20

typedef int *Heap;

typedef struct pqueue{
    Heap h;
    int size, count;
} pqueue;

typedef struct pqueue *Pqueue;

int father(int i){
    return i/2;
}

void swap(Heap h, int i, int j){
    int tmp = h[i];
    h[i] = h[j];
    h[j]=tmp;
}

void heapify_up(Heap h, int i){
    if(i>1){
        int j = father(i);
        if (h[i]<h[j]){
            swap(h, i, j);
            heapify_up(h, j);
        }
    }
}

void heapify_down(Heap h, int i, int n){
    if(2*i<=n){
        int j;
        if(2*i==n)
            j = 2*i;
        else
            j=h[2*i]<h[2*i+1] ? 2*i : 2*i +1;
        if(h[j]<h[i]){
            swap(h,i,j);
            heapify_down(h,j,n);
        }
    }
}

Pqueue pqueue_new(int n){
    Pqueue p = malloc(sizeof(Pqueue));
    if (p){
        p -> h = malloc((sizeof(Heap)*n)+1);
        if (p->h){
            p->size = n+1;
            return p;
        }
    }
    else {
        printf("Malloc failure.\n");
        exit(EXIT_FAILURE);
    }
}

void pqueue_destroy(Pqueue p){
    free(p->h);
    free(p);
}

int pqueue_length(Pqueue p){
    return p -> size;
}

void pqueue_insert(Pqueue p, int item){
    if (p->count < pqueue_length(p)){
        p->h[++p->count] = item;
        heapify_up(p->h, p->count);
    }
}

int pqueue_extractmin(Pqueue p){
    int min = p->h[1];
    swap(p->h,1, p->count);
    p->count--;
    if(p->h[1] > p->h[2] || p->h[1] > p->h[3])
        heapify_down(p->h, 1, p->count);
    return min;
}

void pqueue_sort(int a[], int l, int r){
    Pqueue p = pqueue_new(r-l);
    for(int i=l; i<r; i++)
        pqueue_insert(p,a[i]);
    while(p->count!=0)
        printf("%d, ", pqueue_extractmin(p));
}

int *randomArray(int n){
    int *arr = malloc(sizeof(int)*n);
    if (arr){
        srand(time(NULL));
        for(int i=0; i<n; i++)
            arr[i] = (rand()%100)+1;
        return arr;
    }
    else{
        printf("Creazione dell'array fallita.\n");
        exit;
    }
}

void printArray(int *a, int n){
    for(int i=0; i<n; i++)
        printf("%d, ",a[i]);
    printf("\n");
}

int main(){
    int *a = randomArray(N);
    printf("Array:          ");
    printArray(a,N);
    printf("Array ordinato: ");
    pqueue_sort(a,0,N);
    return 0;
}
