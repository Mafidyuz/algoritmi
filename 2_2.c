#include <stdio.h>

int main() {
	int n = 0;
	int somma =0;
	int c = 0; 
	do {
		printf("Inserire numero: ");
		scanf("%d", &n);
		somma+=n;
		if (n!= 0)
			c+=1;
	}
	while (n != 0);
	float media = (float)somma/c;
	printf("La media dei numeri è %f\n",media);
}