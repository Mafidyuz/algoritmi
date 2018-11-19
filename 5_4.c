#include  <stdio.h>

int collatz(int n){
    return n%2==0? n/2:n*3+1;
}

int main(){
    int n;
    int lunghezza = 0;
    printf("Inserire n: ");
    scanf("%d",&n);
    while(n!=1){
        lunghezza++;
        printf("%d ",n);
        n=collatz(n);
    }printf("%d \n",n);
    printf("Lunghezza: %d\n",++lunghezza);
    return 0;
}
