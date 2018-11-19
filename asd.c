#include "libpsgraph.h"
#include <stdio.h>

void koch(int x, int i){

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

int main() {
    start("curva_koch.ps");
    koch(150,3);
    end();
    return 0;
}
