#include <stdio.h>

int main() {
	int counter = 0;
	int dot = 0;
	char c;
	char str[100] = {0};
	printf("Inserire parola: ");
	do {
		c = getchar();
		str[counter++] = c;
		if (c == '.')
			dot = counter-1;
	}while(c!='.');

	for(int i=0; i<dot; i++){
		if(str[i]!=str[dot-1-i]){
			printf("Parola non palindroma.\n");
			return 0;
		}
		printf("Parola palindroma.\n");
		return 0;

	}
}
