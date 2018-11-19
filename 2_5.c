#include <stdio.h>

int main() {
	int k;
	char c;
	printf("Inserire la chiave di cifratura:  ");
	scanf("%d",&k);
	printf("Inserire la frase da cifrare: ");
	do {
		c = getchar();
		if (c<='z'&& c>='a')
			printf("%c",'a'+(c-'a'+k)%26);
		else if (c<='Z' && c>='A')
			printf("%c",'A'+(c-'A'+k)%26);
		else
			printf("%c",c);
	}
	while (c!='.');
}
