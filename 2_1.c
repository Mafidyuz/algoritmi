#include <stdio.h>

int main() {
	int n = 0;
	int conta =0;
	do {
		printf("Inserire numero: ");
		scanf("%d", &n);
		conta+=n;
	}
	while (n != 0);
	printf("La somma dei numeri è %d\n",conta);
}