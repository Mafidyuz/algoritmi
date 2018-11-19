#include <stdio.h>

int *smallest(int a[], int n){
    int *min = &a[0];
    int *p = a;
    for (p=&a[0]; p<&a[n]; p++)
        if (*p < *min)
            min = p;
    return min;
}

int main() {
    int a[11] = {6,12,2,4,23,5,6,7,8,100,9};
    printf("Il valore minimo di a è %d\n",*smallest(a,11));
    return 0;
}
