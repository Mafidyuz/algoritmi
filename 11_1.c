#include <stdlib.h>
#include <stdio.h>

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

int main(){
    int *p = my_malloc(1);
    printf("%lu\n",sizeof(p));
    p = my_realloc(p, 10);
    printf("%lu\n",sizeof(p));
    return 0;
}
