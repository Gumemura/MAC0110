#include <stdio.h>

#define MAX 100

int main(){
	int cont = 1, quant = 0, soma = 0, acima = 0;
	float media, div, dendo;
	int notas[MAX];

	printf("\nQuantidade de notas: ");
	scanf("%d", &quant);

	printf("Insira as notas: \n");
	for(int q = 0; q < quant; q++){
		printf("Nota %d: ", cont);
		scanf("%d", &notas[q]);

		soma += notas[q];
		cont++;
	}

	printf("\n%d", soma);

	div = soma;
	dendo = quant;
	media = (div/dendo);

	for(int w = 0; w < quant; w++){
		if(notas[w] >= media)
			acima++;
	}



	printf("\nMedia : %.2f", media);
	printf("\nAcima da media: %d", acima);
}