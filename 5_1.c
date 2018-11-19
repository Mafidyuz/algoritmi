#include <stdio.h>

int pot(int b, int e){
    if (e==0)
        return 1;
    else {
        int res = b;
        for(int i=1; i<e; i++)
            res*=b;
        return res;
    }
}

int main() {
    int b,e;
    printf("Inserire base ed esponente (b^e): ");
    scanf("%d^%d",&b,&e);
    printf("%d^%d = %d\n",b,e,pot(b,e));
    return 0;
}
