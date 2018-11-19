#include <stdio.h>

int main() {

	int numero[100]= {0};
	int end=0;
	int n = 0;

	do{
		printf("Inserire numero: ");
		scanf("%d",&n);
		int i;
		for(i=end++; i>0;i--){
			if(numero[i-1]>n && n!=0)
				numero[i]=numero[i-1];
			else
				break;
		}
		numero[i]=n;
	}while(n!=0);
	for (int j=0;j<end-1;j++)
		printf("%d, ",numero[j]);
	return 0;
}
