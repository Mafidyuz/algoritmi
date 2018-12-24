#include <stdlib.h>
#include <stdio.h>

struct queue{
    int n;
    struct queue *next;
};

typedef struct queue *Queue;

Queue createqueue(){
    return NULL;
}

Queue enqueue(Queue q, int n){
    Queue new = malloc(sizeof(struct queue));
    new->n = n;
    if(!q){
        return new;
    }
    else{
        Queue s = q;
        while(q->next)
            q = q->next;
        q->next = new;
        return s;
    }
}

void queue_print(Queue q){
    while(q){
        printf("%d, ",q->n);
        q = q->next;
    }
    printf("\n");
}

void queue_destroy(Queue *q){
    while(*q!=NULL){
        Queue s = *q;
        free(*q);
        *q = s->next;
    }
}

int dequeue(Queue *q){
    if(*q){
        int i = (*q)->n;
        *q = (*q)->next;
        return i;
    }
    else
        return 0;
}
