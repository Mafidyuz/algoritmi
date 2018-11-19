#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#define N 20

void stampa(int a[], int lung){
    for(int i=0; i<lung; i++)
        printf("%d, ",a[i]);
    printf("\n\n");
}

void scambia(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void selectionsort(int a[], int n){
    if(n==0 || n==1)
        exit;
    else{
        int max = a[0];
        int imax = 0;
        for(int i=1; i<n; i++){
            if (max < a[i]){
                max = a[i];
                imax = i;
            }
        }
        scambia(a, imax, n-1);
        selectionsort(a, n-1);
    }
}

void merge(int a[], int l, int m, int r,int x[]) {
    int i = l;
    int j = m;
    int k = 0;
    while (i<m && j<r)
        x[k++] = a[i]<=a[j]? a[i++] : a[j++];
    if(i<m)
        for(int p1=i;p1<m;p1++)
            x[k++]=a[p1];
    else
        for(int p2=j;p2<r;p2++)
            x[k++]=a[p2];
    for(k=0; k<r-l;k++)
        a[l+k]=x[k];
}


void mergesort(int a[], int l, int r, int x[]){
    if (r-l>1){
        int m=(r+l)/2;
        mergesort(a,l,m,x);
        mergesort(a,m,r,x);
        merge(a,l,m,r,x);
    }
}


int main() {
    srand(time(NULL));
    int a[N],x[N];
    for(int i=0; i<N;i++)
        a[i]=rand()%N+1;

    stampa(a,N);
    mergesort(a,0,N,x);
    stampa(x,N);
    return 0;
}
