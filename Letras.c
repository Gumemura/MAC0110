#include <stdio.h>

int main(){
	char letra = '1';
	int contador = 0, armazem = 0, contadorPrint = 1;

	printf("Insira os caracteres do texto\n\n");

	printf("Caractere %d: ", contadorPrint);
	scanf("%c", &letra);

	while(letra != '.'){
		if(letra != '\0'){
			//printf("%s", letra);
			if(letra != ' ' && letra != '.'){
				contador++;
			}else{
				if(armazem < contador){
					armazem = contador;
					contador = 0;
				}
			}
			contadorPrint++;
			//printf("Caractere %d: ", contadorPrint);
			scanf("%c", &letra);
		}
	}

	printf("\n\nA maior palavra tem %d letras!", armazem);
}