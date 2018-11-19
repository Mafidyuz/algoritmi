#include <stdio.h>

int main() {
	int studente[5][5];
	
	for(int i=0; i<5; i++){
		printf("Inserire i risultati dello studente %d di programmazione, continuo, archi, logica e lfa: ",i);
		scanf("%d %d %d %d %d",&studente[i][0],&studente[i][1],&studente[i][2],&studente[i][3],&studente[i][4]);
	}
	printf("\n");
	for(int i=0; i<5; i++) {
		float media=0;
		for(int j=0; j<5; j++)
			media+=studente[i][j];
		printf("La media dello studente %d è %f \n",i,media/5);
	}
	printf("\n");
	
	for(int j=0; j<5; j++){
		float media=0;
		for(int i=0; i<5; i++) {
			media+=studente[i][j];
		}
		printf("La media dell'esame %d è %f\n",j,media/5);
	}
	printf("\n");
	return 0;
}