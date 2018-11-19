#include <stdio.h>
#include <ctype.h>

int main() {
    int carattere[26] = {0};
    char c = '.';

    printf("Inserire due stringe: ");
    do {
        c = getchar();
        if (isalpha(c)){
            char x = islower(c)?'a':'A';
            carattere[c-x]++;
        }
    }while (c!=' ');

    while (c!='\n'){
        c = getchar();
        if (isalpha(c)){
            char x = islower(c)?'a':'A';
            carattere[c-x]--;
        }
    }
    for(int i=0; i<26; i++){
        if (carattere[i] != 0){
            printf("Le due parole inserite non sono anagrammi.\n");
            return 0;
        }
    }
    printf("Le due parole sono anagrammi.\n");
    return 0;
}
