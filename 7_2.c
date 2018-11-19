// Scrivete una funzione con prototipo void scambia(int *p, int *q) che scambi i valori delle due variabili puntate da p e q.

#include <stdio.h>

void scambia(int *p, int *q){
    int t = *p;
    *p = *q;
    *q = t;
}

int main() {
    int p,q;
    printf("Inserire due interi p e q: ");
    scanf("%d %d",&p, &q);
    scambia(&p,&q);
    printf("p = %d q = %d\n",p,q);
    return 0;
}
