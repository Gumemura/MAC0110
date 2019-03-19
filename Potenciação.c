#include <stdio.h>

int main(){
	int base = 0, expoente = 0, resultado = 0;

	printf("Insira a base: ");
	scanf("%d", &base);

	printf("Insira o expoente (maior que 0): ");
	scanf("%d", &expoente);

	if(expoente == 0){
		resultado = 1;
	}else if(expoente == 1)
		resultado = base;
	else{

		resultado = base*base;

		for(int i = 2; i < expoente; i++){
			resultado *= base;
		}
	}

	printf("\n\n");
	printf("RESULTADO: %d", resultado);

	return 0;
}