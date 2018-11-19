#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *read_line(){
    char *s = malloc(1*sizeof(char));
    char *tmp;
    char c;
    int counter = 0;
    do{
        c = getchar();
        if (c=='\n')
            s[counter]='\0';
        else
            s[counter++]=c;
        tmp = realloc(s, (counter+1)*sizeof(char));
        if (tmp)
            s = tmp;
        else
            return NULL;
    }while (c!='\n');
    return s;
}

char *read_word(){
    char *s
}

int main(){
    char *s = read_line();
    for (int i=0; i<strlen(s); i++)
        printf("%c",s[i]);
    printf("\n");
    return 0;
}
