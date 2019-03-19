#include <stdio.h>

int main(){

	int contadorPar = 0, contadorImpar = 0, comparador;
	float numeroDado;

	printf("Insira um número. Lhe direir quantos deles são pares e quantos são ìmpares (fechar sequência com o número 0): \n");

	while(numeroDado != 0){
		scanf("%f", &numeroDado);

		comparador = numeroDado/2;

		if(numeroDado/2 == comparador){
			contadorPar++;
		}else{
			contadorImpar++;
		}
	}

	printf("\n\n\t\t\t#####RESULTADO#####\n\n");
	printf("\t\t\tPARES: %d\n\n", contadorPar - 1);
	printf("\t\t\tIMPARES: %d\n\n", contadorImpar);

	return 0;
}