#include <stdio.h>
#include <ctype.h>

char *maiuscolo(char *stringa) {
    char *p;
    p = stringa;
    do
        *stringa = toupper(*stringa);
    while(*stringa++!='\0');
    return p;
}

int main(){
    char str[100] = {0};
    char c;
    int counter = 0;
    printf("Inserire stringa: ");
    do {
        c=getchar();
        str[counter++]=c;
    } while (c!='\n');
    printf("%s\n",maiuscolo(str));
    return 0;
}
