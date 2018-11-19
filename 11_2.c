#include <stdio.h>
#include <stdlib.h>


void *my_malloc(int size){
    int *p = malloc(size);
    if (p == NULL){
        printf("Allocazione fallita.\n");
        exit;
    }
    else {
        printf("Allocazione riuscita.\n");
        return p;
    }
}

void *my_realloc(void *p, int size){
    p = realloc(p, size);
    if (p==NULL){
        printf("Reallocazione fallita.\n");
        exit;
    }
    else {
        printf("Reallocazione riuscita.\n");
        return p;
    }
}

int main() {
    int *a, size = 2;
    int n, c = 0;
    a = my_malloc(size*sizeof(int));
    do {
        scanf("%d",&n);
        if (n!=0)
            a[c++]=n;
        if (c==size){
            size*=2;
            a = my_realloc(a, sizeof(int)*size);
        }
    }while (n!=0);
    for(int i=c-1; i>=0; i--)
        printf("%d ",a[i]);
    return 0;
}
