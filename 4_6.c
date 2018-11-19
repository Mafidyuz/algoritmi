#include <stdio.h>
#include <ctype.h>

typedef struct {
    char nome[10];
    int numero;
} Contatto;

int main() {
    Contatto rubrica[50] = {0};
    int opz, counter=0;
    do {
        printf("1) Visualizzare rubrica.\n2) Inserire nuovo numero.\n3) Exit\nOpzione: ");
        scanf("%d",&opz);
        printf("\n");
        if(opz==1)
            for(int i=0; i<50; i++)
                if (    rubrica[i].numero != 0)
                    printf("Contatto: %s\nNumero: %d\n\n",rubrica[i].nome,rubrica[i].numero);

        if(opz==2){
            printf("Inserire contatto e numero: ");
            char c = ' ';
            int x = 0;
            do {
                c = getchar();
                if (isalpha(c))
                    rubrica[counter].nome[x++] = c;
            }while (c!=' ');
            scanf("%d", &rubrica[counter++].numero);
        }
    }while(opz != 3);
    return 0;
}
