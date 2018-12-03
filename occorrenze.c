#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define WORD 20

typedef struct occorrenza{
    char* word;
    int n;
} occorrenza;

struct bit_node {
    occorrenza *occorrenza;
    struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

Bit_node insert(Bit_node p, char *s){
        if (p==NULL){
            p = malloc(sizeof(Bit_node));
            p -> occorrenza = malloc(sizeof(occorrenza));
            p -> occorrenza -> word = s;
            p -> occorrenza -> n = 1;
            p -> r = NULL;
            p -> l = NULL;
        }
        else{
            if(strcmp(p->occorrenza->word,s)==0){
                p->occorrenza->n = p->occorrenza->n+1;
            }
            else if (strcmp(p->occorrenza->word,s)<0)
                p->r = insert(p->r,s);
            else if (strcmp(p->occorrenza->word,s)>0)
                p->l = insert(p->l,s);
        }
        return p;
}

void bist_printnode(Bit_node p){
    printf("%s %d\n",p -> occorrenza -> word, p -> occorrenza -> n);
}

void bist_orderprint(Bit_node p){
    if(p){
        bist_orderprint(p->l);
        bist_printnode(p);
        bist_orderprint(p->r);
    }
}

void bist_reverseprint(Bit_node p){
    if(p){
        bist_reverseprint(p->r);
        bist_printnode(p);
        bist_reverseprint(p->l);
    }
}

char* toLower(char *s){
    int c=1;
    char *new = malloc(c);
        while(isalpha(*s)){
            new = realloc(new,++c);
            *(new+c-2) = tolower(*(s++));
        }
    return new;
}

int n_word(Bit_node p, char *s){
    if(p){
        if(strcmp(p->occorrenza->word,s)==0)
            return p->occorrenza->n;
        if(strcmp(p->occorrenza->word,s)<0){
            return n_word(p->r,s);
        }
        else
            return n_word(p->l,s);
    }
    else
        return 0;
}

int main(){
    char *s;
    Bit_node root=NULL;

    do {
        s = malloc(WORD);
        scanf("%s",s);
        s = toLower(s);
        if(strcmp(s,"stop")!=0)
            root = insert(root,s);
    }while (strcmp(toLower(s),"stop")!=0);

    char **words= malloc(sizeof(char**));
    int c = 0;

    do {
        s = malloc(WORD);
        scanf("%s",s);
        s = toLower(s);
        if(strcmp(s,"stop")!=0){
            words = realloc(words,sizeof(char**)*(c+2));
            words[c]=malloc(sizeof(strlen(s)));
            strcpy(words[c++],s);
        }
    }while(strcmp(toLower(s),"stop")!=0);

    printf("\nOCCORRENZE DI PAROLE NEL TESTO IN ORDINE ALFABETICO:\n****************************************************\n");
    bist_orderprint(root);

    printf("\nOCCORRENZE DI PAROLE NEL TESTO IN ORDINE INVERSO:\n****************************************************\n");
    bist_reverseprint(root);

    printf("\nRICERCA DI PAROLE:\n******************\n");
    for(int i=0; i<c; i++){
        printf("%s %d\n",words[i],n_word(root,words[i]));
    }

    return 0;
}
