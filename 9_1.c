#include <stdio.h>
#include <string.h>
int main() {
    char str[100] = {0};
    char *p = &str[0];
    printf("Inserire stringa: ");
    scanf("%s",str);
    char *end = &str[(int)strlen(str)-1];
    int counter = 0;
    for (p=&str[0]; p<&str[(int)strlen(str)]; p++)
        if (*p != *end--){
            printf("Parola non palindroma.\n");
            return 0;
        }
    printf("Parola palindroma.\n");
    return 0;
}
