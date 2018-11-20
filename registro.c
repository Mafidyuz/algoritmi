#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro {
    char **name;
} registro;

void *newBook(registro *r, int n){
    registro *tmp= malloc(sizeof(registro));
    if (tmp==NULL){
        printf("Allocazione fallita.\n");
        return r;
    }
    else {
        printf("Allocazione riuscita.\n");
        tmp -> name = malloc(sizeof(char*)*n);
        return tmp;
    }
}

void book(registro *r, int k, char *name, int n){
    if (k<n && (r->name[k])==NULL && k>=0) {
        r -> name[k] = malloc(sizeof(name)+1);
        strcpy(r->name[k],name);
        printf("Prenotazione avvenuta con successo.\n");
    }
    else if(k>=0 && k<n)
        printf("Prenotazione già occupata da %s.\n", r -> name[k]);
    else
        printf("Prenotazione fallita.\n");
}

void cancel(registro *r, int k){
    if(r -> name[k]){
        r -> name[k] = NULL;
    }
    else
        printf("Posto già libero.\n");
}

void move(registro *r, int from, int to){
    if(r -> name[from] && !r -> name[to]){
        r -> name[to] = r -> name[from];
        printf("Spostamento avvenuto con successo.\n");
        cancel(r,from);
    }
    else
        printf("Impossibile spostare la prenotazione.\n");
    }

void printBook(registro *r, int n){
    for(int i=0; i<n; i++)
        if (r -> name[i])
            printf("%d) %s\n",i,r->name[i]);
}

int main(){
    registro *r;
    int n, k, from, to;
    char c;
    char *name;
    while((c=getchar()) != 'f') {
        switch(c){
            case 'b':
                scanf("%d",&n);
                r = newBook(r,n);
                break;
            case '+':
                scanf("%d %s",&k,name);
                book(r,k,name,n);   //void book(registro *r, int k, char *name, int n)
                break;
            case '-':
                scanf("%d",&k);
                cancel(r, k);
                break;
            case 'm':
                scanf("%d %d",&from,&to);
                move(r,from,to);
                break;
            case 'p':
                printBook(r,n);
                break;
        }
    }
    return 0;
}
