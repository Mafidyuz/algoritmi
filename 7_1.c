#include <stdio.h>

void split_time(long int tot_sec, int *d,int *h, int *m, int *s){
    *d = tot_sec/(3600*24);
    *h = tot_sec%(3600*24)/3600;
    *m = (tot_sec%(3600*24)%3600)/60;
    *s = (tot_sec%(3600*24)%3600)%60;
}

int main(){
    long int tot_sec;
    int hours, minutes, seconds, days = 0;
    printf("Inserire tempo in secondi: ");
    scanf("%ld",&tot_sec);
    split_time(tot_sec,&days,&hours,&minutes,&seconds);
    printf("Il tempo corrisponde a %dd, %dh, %dm, %ds\n",days,hours,minutes,seconds);
    return 0;
}
