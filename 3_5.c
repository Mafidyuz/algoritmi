#include <stdio.h>

int main() {
	char string[100] = {0};
	char c;
	int counter = 0;
	do {
		c=getchar();
		string[counter++] = c;
	}while(c!='\n');
	
	int first_space = 0;
	int last_space = 0;
	char delete;
	for(int i=0; i<100; i++) {
		if (string[i] == ' ' || string[i]=='\n') {
			int last_space = i;
			delete = string[i-1];
			for(int j = first_space; j<=last_space; j++){
				if (string[j] != delete)
					printf("%c",string[j]);
			}
			first_space = last_space;
		}
	}
	return 0;
}

