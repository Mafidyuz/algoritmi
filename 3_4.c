	#include <stdio.h>
#include <ctype.h>

int main() {
	char string[100] = {0};
	char c;
	int counter=0;
	printf("Inserire testo da cifrare: ");
	do {
		c = getchar();
		string[counter++] = c;
	}while(c!='.');
	int k;
	printf("Inserire la chiavi di cifratura: ");
	scanf("%d",&k);
	for (int i=0; i<100; i++)
		printf("%c",isalpha(string[i])? isupper(string[i])? 'A'+(string[i]-'A'+k)%26:'a'+(string[i]-'a'+k)%26:string[i]);
	return 0;
}
