#include <stdio.h>
#include <ctype.h>

int main() {
    int carattere[26] = {0};
    char c = '.';

    do {
        c = getchar();
        if (isalpha(c)){
            char x = islower(c)?'a':'A';
            carattere[c-x]++;
        }
    }while (c!='.');

    for(int i=0; i<26; i++){
        if(carattere[i]>0){
            printf("%c: ",'A'+i);
            for(int j=0; j<carattere[i]; j++)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}
