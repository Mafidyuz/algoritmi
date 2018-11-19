#include <stdio.h>
#include <stdio.h>

int isPrimo(int n){
    int last_primo=0;
    if (n==1)
        return 0;
    for (int i=2; i<n/2+1; i++)
        if (n%i==0)
            return 0;
    return 1;

}

int main() {
    int n;
    printf("Inserire un numero: ");
    scanf("%d",&n);
    printf("Il numero %d %sè primo.\n",n,isPrimo(n)?"":"non ");
    return 0;
}
