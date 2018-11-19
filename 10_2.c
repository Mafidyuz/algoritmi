#include <stdio.h>

int main(int argc, char *argv[]) {
    int i=0;
    while (argv[1][i] != '\0'){
        if (argv[1][i]=='a' || argv[1][i]=='e' || argv[1][i]=='i' || argv[1][i]=='o' || argv[1][i]=='u') {
            printf("%cf%c",argv[1][i],argv[1][i]);
            i++;
        }
        else
            printf("%c",argv[1][i++]);
    }
    return 0;
}
