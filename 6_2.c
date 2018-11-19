#include "libpsgraph.h"
#include <stdio.h>
#include <stdlib.h>

void koch(double x, int i){

    if (i==0){
        draw(x);
    }
    else{
        koch(x/3,i-1);
        turn(300);
        koch(x/3,i-1);
        turn(120);
        koch(x/3,i-1);
        turn(300);
        koch(x/3,i-1);
    }


}

int main(int argc, char* argv[]) {
    start("fiocco_koch.ps");

    int n = atoi(argv[1]);
    printf("%d",n);
    for (int i=0; i<3; i++){
        koch(243.0,n);
        turn(120);
    }
    end();
    return 0;
}
