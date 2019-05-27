#include <stdio.h>


int conversor(char * letraConversao){
	#define DIF 'a' - 'A'

	if(*letraConversao >= 'a' && *letraConversao <= 'z')
		*letraConversao -= DIF;

	if(*letraConversao == 'a' || *letraConversao == 'e' || *letraConversao == 'i' || *letraConversao == 'o' || *letraConversao == 'u')
		return 1;
	else
		return 0;
}

int main(){
	#define MAX 30

	char l[MAX];
	int vogais = 0, consoantes = 0;

	printf("Digite seu texto:\n");
	scanf("%s", &l);

	for(int q = 0; q < MAX; q++){
		if(l[q] != NULL){
			conversor(&l[q]);

			if(conversor(&l[q]) == 1)
				vogais++;
			else
				consoantes++;

		}
	}

	printf("\n%s", l);

	printf("\n\nVogais: %d\nConsoantes: %d", vogais, consoantes);
}

