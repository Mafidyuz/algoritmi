/*

#include <stdio.h>
int main() {
	int n;
	printf("Inserire un intero n: ");
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			printf("%c ",i%2==0? '+':'o');
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
int main() {
	int n;
	printf("Inserire un intero n: ");
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			printf("%c ",(j+i)%2==0? '+':'o');
		printf("\n");
	}
	return 0;
}


#include <stdio.h>
int main() {
	int n;
	printf("Inserire un intero n: ");
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++){
			if (i == j)
				printf("%c ",'|');
			else if(j>i)
				printf("%c ",'+');
			else
				printf("%c ",'o');
		}
		printf("\n");
	}
	return 0;
}

*/

#include <stdio.h>
int main() {
	int n;
	printf("Inserire un intero n: ");
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		for (int j=n+1; j>=0; j--){
			printf("%c",j==i || i==n-3 && j ==n+1 || i==n-2 && j==n ?'*':'.');
		}
		printf("\n");
	}
	return 0;
}