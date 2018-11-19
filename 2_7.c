#include <stdio.h>
#include <stdbool.h>
	
int main() {
	char c;
	int aperte = 0;
	int chiuse = 0;
	do {
		c = getchar();
		if (c == '(')
			aperte++;
		else if(c==')')
			chiuse++;
		if (chiuse> aperte){
			printf("La stringa ha troppe parentesi chiuse!\n");
			return 0;
		}
	}
	while (c!='.');
	if (aperte != chiuse) 
		printf("La stringa non è un'espressione ben parentesizzata!");
	else
		printf("La stringa è un'espressione ben parentesizzata!");
	return 0;
}

