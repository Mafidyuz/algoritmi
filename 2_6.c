#include <stdio.h>

int main(){
	int mese, giorno;
	printf("Inserisci il numero del mese (1 = gennaio, ..., 12 = dicembre): ");
	scanf("%d",&mese);
	printf("Inserisci il giorno di inizio mese (1 = lunedi, ..., 7 = domenica): ");
	scanf("%d",&giorno);
	giorno--;
	int ngiorni = 28;
	switch(mese) {
		case 2:
			break;
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			ngiorni +=3;
			break;
		case 4: case 6: case 9: case 11:
			ngiorni +=2;
			break;
		default:
			ngiorni=0;
			break;
	}
	if (ngiorni!= 0) {
		printf("L\tM\tM\tG\tV\tS\tD\n");
		
		for (int i=0;i<giorno;i++)
			printf("%c",'\t');
		
		for(int i =1; i<=ngiorni; i++){
			printf("%d\t",i); 
			giorno+=1;
			if (giorno%7 ==0 )
				printf("\n");
		}
		printf("\n");
	
	}
	else
		printf("Mese non riconosciuto.\n");
	return 0;
}
