#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
	srand(time(NULL));
	int r,c;
	printf("Inserire numeri di righe e colonne (r, c): ");
	scanf("%d, %d",&r, &c);
	char mat[r][c];
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++){
			mat[i][j] = rand()%4==0? 'A'+rand()%26:'*';
			printf("%c ",mat[i][j]);
		}
		printf("\n");
	}
	
	for(int j=0; j<c; j++) {
		int la;
		for(int i=r-1; i>=0; i--){	
			if (mat[i][j] == '*'){
				la = i;
				break;
			}
		}
		for(int i=la; i>=0; i--) {
			if(isalpha(mat[i][j])){
				mat[la--][j] = mat[i][j];
				mat[i][j] = '*';
			}
		}
	}
	
	printf("\n");
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++){
			printf("%c ",mat[i][j]);
		}
		printf("\n");
	}
	
}
