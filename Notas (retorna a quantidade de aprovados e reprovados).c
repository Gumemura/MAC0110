#include <stdio.h>

int main (){
	int notas, manosReaval = 0, manosDP = -1, manosAprovados = 0;

	printf("\nInsira valor das notas entre 0 e 100 (para terminar, inserir -1)\n");

	while(notas != -1){
		scanf("%d", &notas);
		if(notas < 0 || notas > 100){
			printf("Inserir valor válido! (0 a 100)\n");
		}else{
			if(notas < 30){
				manosDP++;
			}else if(notas > 30 && notas < 50){
				manosReaval++;
			}else{
				manosAprovados++;
			}
		}
	}

	printf("\n\n");
	printf("\t\t\t\t\t##### RESULTADO #####\n\n");
	printf("\t\tAprovados: %d", manosAprovados);
	printf("\t\tReaval: %d", manosReaval);
	printf("\t\tReprovados: %d\n\n", manosDP);


	return 0;
}