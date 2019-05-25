#include <stdio.h>

int main(){
	char letra;
	int contador = 0, armazem = 0, contadorPrint = 1;

	printf("Insira os caracteres do texto\n\n");

	while(letra != '.'){
		printf("Caractere %d: ", contadorPrint);
		scanf("%c", &letra);

		if(letra != ' ' && letra != '.'){
			contador++;
		}else{
			if(armazem < contador){
				armazem = contador;
				contador = 0;
			}
		}
		contadorPrint++;
	}

	printf("\n\nA maior palavra tem %d letras!", armazem);
}