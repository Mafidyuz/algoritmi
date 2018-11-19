#include <stdio.h>
#include <string.h>

void hanoi(int n, char from[], char temp[], char to[]){
    if(n==1){
        int l_from = (int)strlen(from);
        int l_temp = (int)strlen(temp);
        int l_to = (int)strlen(to);
        to[l_to]=from[l_from-1];
        from[l_from-1] = 0;
        printf("%s, %s, %s\n",from, temp, to);
    }
    else{
        hanoi(n-1, from, to, temp);
        int l_from = (int)strlen(from);
        int l_temp = (int)strlen(temp);
        int l_to = (int)strlen(to);
        to[l_to]=from[l_from-1];
        from[l_from-1] = 0;
        printf("%s, %s, %s\n",from, temp, to);
        hanoi(n-1,temp,from,to);
    }
}


int main(){
    int n;
    printf("Altezza pila: ");
    scanf("%d",&n);
    char from[64] = {0};
    char temp[64] = {0};
    char to[64] = {0};
    for(int i=0; i<n; i++){
        from[i]='A'+i;
        temp[i]=0;
        to[i]=0;
    }
    hanoi(n,from,temp,to);
    return 0;
}
