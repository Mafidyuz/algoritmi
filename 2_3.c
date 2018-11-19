#include <stdio.h>

int main() {
	int counter = 0;
	int somma =0;
	while (counter < 10){
		int n;
		printf("Inserire numero: ");
		scanf("%d", &n);
		if (n != 0) {
			somma +=n;
			counter+=1;
		}
	}
	printf("La somma dei 10 numeri diversi da zero è %d\n",somma);
}