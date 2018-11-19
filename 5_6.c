#include <stdio.h>

int calls_r=0;

int fibo(int n) {
    calls++;
    return n==1 || n==2? 1:fibo(n-1)+fibo(n-2);
}

int fibo2(int n){
    int a,b,c=1;
    for(int i=2;i<=n;i++){
        calls
        a=b;
        b=c;
        c=a+b;
    }
    return c;
}

int main(){
    int n;
    printf("Inserire numero: ");
    scanf("%d",&n);
    printf("Il numero di fibonacci è %d\n",fibo2(n));
//    printf("Numero di chiamate: %d\n",calls);
    return 0;
}
