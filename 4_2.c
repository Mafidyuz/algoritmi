#include <stdio.h>
#include <math.h>

int main() {
    int b,n;
    printf("Inserire base e numero: ");
    scanf("%d %d",&b,&n);
    int nBase10 = 0;
    int conta = 0;
    while(n!= 0) {
        int cifra = n%10;
        n/=10;
        nBase10+= cifra*pow(b,conta++);
    }
    printf("Il numero in base %d è %d.\n",b,nBase10);
    return 0;
}
