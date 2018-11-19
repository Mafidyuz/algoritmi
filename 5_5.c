#include <stdio.h>

void quadratoMagico(int n){
    int mat[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mat[i][j]=0;
    int j = n/2;
    int i = 0;
    int c = 0;
    while (c<n*n){
        mat[i][j] = ++c;
        i=i-1<0?(n+i-1)%n:i-1;
        j=(j+1)%n;
        if (mat[i][j]!=0){
            j=j-1<0? (n+j-1)%n : j-1;
            i=(i+2)%n;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%d\t",mat[i][j]);
        printf("\n");
    }
}

int main(){
    int n;
    printf("Inserire dimensione quadrato: ");
    scanf("%d",&n);
    quadratoMagico(n);
    return 0;
}
