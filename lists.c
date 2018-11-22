#include <stdio.h>
#include <stdlib.h>

struct element {
    int data;
    struct element *next;
};

typedef struct element element;

element *insert(int n, element* h){
    element *new = malloc(sizeof(element));
    if (new==NULL)
        exit;
    else{
        new -> data = n;
        new -> next = h;
        return new;
    }
}

void printList(element* h){
    while (h->next){
        printf("%d, ",h->data);
        h = h->next;
    }
    printf("\n");
}

int isMember(int n, element* h){
    while(h->next){
        if (h->data==n)
            return 1;
        h = h->next;

    }
    return 0;
}

element* delete (int n, element* h){
    element *start = h;
    element *prev = NULL;

    if (isMember(n,h)){
        if (h->data==n){
            start = h -> next;
            free(h);
            return start;
        }
        while ((h -> data)!=n){
            prev = h;
            h = h -> next;
        }
        prev -> next = h -> next;
        free(h);
    }
    return start;
}

void destroy(element *h){
    element *start = h;
    element *prev = NULL;
    while (h){
        prev = h;
        h = h->next;
        free(prev);
    }
    start -> next = NULL;
}

int *listToArray(element* h, int n){
    int *a = malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        a[i]=h->data;
        h=h->next;
    }
    return a;
}

int main(){
    element *head=malloc(sizeof(element));
    head -> next = NULL;
    int *rev;
    char c;
    int n, counter = 0;
    while ((c=getchar())!='f') {
        switch(c){
            case '+':
                scanf("%d",&n);
                if (!isMember(n,head)){
                    head = insert(n,head);
                    counter++;
                }
                break;
            case 'p':
                printList(head);
                break;
            case '?':
                scanf("%d",&n);
                if (isMember(n,head))
                    printf("Il numero %d è contenuto nella lista.\n",n);
                else
                    printf("Il numero %d non è contenuto nella lista.\n",n);
                break;
            case '-':
                scanf("%d",&n);
                if(isMember(n,head))
                    counter--;
                head = delete(n,head);
                break;
            case 'c':
                printf("La lista ha larghezza %d.\n",counter);
                break;
            case 'd':
                destroy(head);
                printf("Lista distrutta.\n");
                counter = 0;
                break;
            case 'r':
                rev=listToArray(head,counter);
                for(int i=counter-1; i>=0; i--)
                    printf("%d, ",rev[i]);
                printf("\n");
                free(rev);
        }
    }
    return 0;
}
