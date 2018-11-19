#include <stdio.h>
#include <ctype.h>

int main(){
    int counter = 0;
    char c = '.';
    char voc;
    printf("Stringa: ");
    do {
        if (counter++ == 0){
            voc = getchar();
            getchar();
        }
        c=getchar();
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            c = voc;
        printf("%c",c);
    }while(c!='.');
    return 0;
}
