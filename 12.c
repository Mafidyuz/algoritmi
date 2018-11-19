#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Registro {
    char **cliente;
} Registro;

Registro *newBook(Registro *r, int n) {
    Registro *tmp = malloc(sizeof(char*)*n);
    if (tmp){
        printf("Creazione del nuovo registro avvenuta con successo.\n");
        free(r);
        return tmp;
    }
    else {
        printf("Creazione del nuovo registro fallita.\n");
        return r;
    }
}

void printBook(Registro *r, int n){
    for(int i=0; i<n; i++){
        if( r-> *(cliente+i) )
            printf("asd");
    }
}

int main(){
    int n = 100;
    Registro *r = newBook(r, n);
    printBook(r,n);
    //book(r,12,"mario");
    //printf("%s", (r -> cliente);
    return 0;
}
