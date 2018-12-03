#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

struct bit_node {
    int item;
    struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

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

void bit_printnode(Bit_node p){
    printf("%d, ", p -> item);
}

void bit_preorder(Bit_node p){
    if(p){
        bit_printnode(p);
        bit_preorder(p->l);
        bit_preorder(p->r);
    }
}

void bit_inorder(Bit_node p){
    if(p){
        bit_inorder(p->l);
        bit_printnode(p);
        bit_inorder(p->r);
    }
}

void bit_postorder(Bit_node p){
    if(p){
        bit_postorder(p->l);
        bit_postorder(p->r);
        bit_printnode(p);
    }
}

Bit_node bit_new(int n){
    Bit_node b = malloc(sizeof(Bit_node));
    b -> item = n;
    return b;
}

void bit_printassummary(Bit_node p, int spaces){
    if(p){
        for(int i=0; i<spaces; i++)
            printf("  ");
        printf("*");
        if (p->item)
            printf("%d",p -> item);
        printf("\n");
        if ((p->l && p-> r) && (p->l->item || p->r -> item)){
            bit_printassummary(p->l,spaces+1);
            bit_printassummary(p->r, spaces+1);
        }
    }
}

Bit_node bit_arr2tree(int *a, int size, int i){
    Bit_node b = malloc(sizeof(Bit_node));
    b -> r =  malloc(sizeof(Bit_node));
    b -> l =  malloc(sizeof(Bit_node));
    if (i<size)
        b -> item = a[i];
    if(i*2+1 < size)
        b -> l = bit_arr2tree(a, size, i*2+1);
    if(i*2+2 < size)
        b -> r = bit_arr2tree(a, size, i*2+2);
    return b;
}

int main() {
    int *a = randomArray(N);
    printArray(a,N);
    Bit_node b = bit_arr2tree(a,N,0);
    bit_printassummary(b,0);
    return 0;
}
