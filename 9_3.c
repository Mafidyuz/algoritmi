#include <stdio.h>

int lung_stringa(char *s) {
    int c = 0;
    char *p = s;
    while (*p++!='\0')
        c++;
    return c-1;
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

    printf("Lungezza stringa = %d\n",lung_stringa(str));
    return 0;
}
