#include <stdio.h>
#include <string.h>

int smallest_word_index(char *s[], int n){
    int smallest = 0;
    for (int i=1; i<n; i++)
        if (strcmp(s[i], s[smallest]) <0)
            smallest = i;
    return smallest;
}

int main (){
    char *dict[] =  {"ciao", "mondo", "come", "funziona", "z", "bene", "questo","as"};
    int lun = 8;
    int pos = smallest_word_index( dict, lun );
    printf("La parola minima si trova in posizione %d.\n", pos );
    return 0;
}
