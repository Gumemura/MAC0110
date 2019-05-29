#include <stdio.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int quant, valorChecado;

int temX(int arrayInt[]){
	int boolean = FALSE, temXRetorno;

	for(int q = 0; q < quant; q++){
		if(arrayInt[q] == valorChecado){
			temXRetorno = q;
			boolean = TRUE;
		}
	}

	if(boolean == FALSE)
		temXRetorno = -1;

	return(temXRetorno);
}

void addX(int arrayAdd[]){
	int tem = FALSE;

	for(int e = 0; e < quant; e++){
		if(arrayAdd[e] == valorChecado)
			tem = TRUE;
	}

	if(tem == FALSE)
		arrayAdd[quant] = valorChecado;
}

int main(){

	int lista[MAX];

	printf("Insira quantidade de elementos do vetor: ");
	scanf("%d", &quant);

	printf("\nInsira os numeros da lista: ");
	for(int w = 0; w < quant; w++){
		scanf("%d", &lista[w]);
	}

	printf("\nInsira o numero a ser checado: ");
	scanf("%d", &valorChecado);

	if(temX(lista) == -1){
		printf("\n%d nao consta na lista. Vamos adiciona-lo: ", valorChecado);
		addX(lista);

		for (int r = 0; r < (quant + 1); r++){
			printf("%d | ", lista[r]);
		}
	}else{
		printf("\nO numero %d eh o %dth da lista (indice [%d])", valorChecado, temX(lista) + 1, temX(lista));
	}
	
}
