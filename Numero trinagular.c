#include <stdio.h>

int main(){
	int num, n = 1, triMax = 0, triMin = 0;

	printf("Insira numero maior ou igual a zero para verificarmos se ele eh triangular ou nao: ");
	scanf("%d", &num);

	while(triMax <= num){
		triMax = n*(n + 1)*(n + 2);
		n++;
	}

	triMin = (n-2)*(n-1)*(n);

	printf("\n\ntriMax: %d*%d*%d = %d", n-1, n, n+1,triMax);
	printf("\n\ntriMin: %d*%d*%d = %d", n-2, n-1, n, triMin);

	if(num == triMax || num == triMin){
		printf("\n\nO numero %d eh triangular uhuuuuuuuul!!", num);
	}else{
		printf("\n\nO numero %d nao eh triangular :(", num);
	}



	return 0;
}