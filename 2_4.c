#include <stdio.h>

int main() {
	int x = 500;
	char c = ' ';
	int max = 1000;
	int min = 0;
	while (c != '=') {
		printf("Il numero è maggiore, minore o uguale a %d?: ",x);
		scanf(" %c",&c);
		switch(c){
			case '<':
				max = x;
				x = (max+min)/2 ==x ?0:(max+min)/2 ;
				break;
			case '>':
				min = x;
				x = (max+min)/2 ==x ?1000:(max+min)/2 ;
				break;
			case '=':
				break;
			default:
				continue;
		}
	}
	printf("Il tuo numero è %d\n",x);
	return 0;
}