#include <stdio.h>

void max_secondmax (int a[], int n, int *max, int *second_max) {
    *max, *second_max = a[0];
    int *p = a;
    for(p=&a[0]; p<&a[n]; p++){
        printf("%d\n",*p);
        if (*p>*max){
            *second_max = *max;
            *max = *p;
        }
        if (*p>*second_max && *p<*max)
            *second_max = *p;
    }
}
int main() {
    int a[11] = {0,1,2,3,23,5,6,7,9,100,50};
    int max, second_max;
    max_secondmax(a,11,&max, &second_max);
    printf("max: %d | second_max: %d\n",max, second_max);
}
