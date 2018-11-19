#include <stdio.h>

typedef struct {
	int giorno;
	int mese;
	int anno;
} Data;

int main() {
	Data date[100] = {0};
	Data d = {00,00,0000};
	int c = 0;
	do {
		printf("Inserire data (dd/mm/yyyy): ");
		scanf("%d/%d/%d",&d.giorno, &d.mese, &d.anno);
		date[c++] = d;
	}while (d.giorno!=0 || d.mese != 0 || d.anno != 0);

	printf("Inserire data massima (dd/mm/yyyy): ");
	scanf("%d/%d/%d",&d.giorno, &d.mese, &d.anno);

	printf("Date minori di %02d/%02d/%04d:\n\n",d.giorno,d.mese,d.anno);
	for(int i=0; i<c-1; i++) {
		if (date[i].anno<d.anno)
			printf("%02d/%02d/%04d\n",date[i].giorno,date[i].mese,date[i].anno);
		if (date[i].anno == d.anno && date[i].mese<d.mese)
			printf("%02d/%02d/%04d\n",date[i].giorno,date[i].mese,date[i].anno);
		if (date[i].anno == d.anno && date[i].mese==d.mese && date[i].giorno < d.giorno)
			printf("%02d/%02d/%04d\n",date[i].giorno,date[i].mese,date[i].anno);
	}

	return 0;
}
