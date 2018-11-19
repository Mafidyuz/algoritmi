#include <stdio.h>
#include <math.h>

void convertiBase(int base, int n) {
	int cifreNumero[100] = {0};
	int c = 0;
	while (n!=0) {
		cifreNumero[c++] = n%base;
		n/=base;
	}
	int b = 0;
	for(int i=99; i>=0; i--){
		if (cifreNumero[i] != 0)
			b = 1;
		
		if (b)
			printf("%d",cifreNumero[i]);
	}
}

int main() {
	int base, n;
	printf("Inserire una base b e un numero in base 10: ");
	scanf("%d %d",&base,&n);
	printf("Il numero %d in base 10 equivale al numero ",n);
	convertiBase(base,n);	
	printf(" in base %d.\n",base);
	return 0;
} 