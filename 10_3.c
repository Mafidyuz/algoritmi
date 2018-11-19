#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 1;
    printf("%c",argv[1][0]);
    while (argv[1][i]!= '\0'){
        printf( argv[1][i]>argv[1][i-1]? "%c" : "-%c" , argv[1][i]);
        i++;
    }
    return 0;
}
