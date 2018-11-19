#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

enum {left, up, right, down} Direzione;

int main(){
    srand(time(NULL));
    char mat[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++)
            mat[i][j]='.';
    }


    char c ='A';
    int i,j = 0;
    for(int k=0; k<26; k++){
        mat[i][j]=c+k;
        int dir = rand()%4;

        if ((i==0 || mat[i-1][j]!='.') && (i==9 || mat[i+1][j]!='.') && (j==0 || mat[i][j-1]!='.') && (j==9 || mat[i][j+1]!='.'))
            break;

        switch(dir){
            case left:
                if (i>0 && mat[i-1][j]=='.')
                    i-=1;
                else
                    k--;
                break;
            case right:
                if (i<9 && mat[i+1][j]=='.')
                    i+=1;
                else
                    k--;
                break;
            case up:
                if (j>0 && mat[i][j-1]=='.')
                    j-=1;
                else
                    k--;
                break;
            case down:
                if (j<9 && mat[i][j+1]=='.')
                    j+=1;
                else
                    k--;
                break;
            default:
                break;
        }

    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++)
            printf("%c ",mat[i][j]);
        printf("\n");
    }

    return 0;
}
