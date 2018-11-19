#include <stdio.h>

int main() {
    int n;
    printf("Inserire un numero intero: ");
    scanf("%d",&n);
    int cifre[10] = {0};
    
    while (n!=0){
        int cifra = n%10;
        n/=10;
        cifre[cifra]++;
    }

    for(int i=0; i<10; i++)
        if (cifre[i]>1)
            printf("La cifra %d occorre %d volte.\n",i, cifre[i]);
    return 0;
}
