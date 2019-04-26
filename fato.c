/****************************************************************
    Nome: Guilherme Umemura
    NUSP: 9353592

    Fonte e comentários: 

****************************************************************/

#include <stdio.h>
#include <math.h>

float senTaylor(float x){
	int k = 1;
	float termoAntigo, termoNovo, somatoria;

	somatoria = termoAntigo = x;

	do{
		termoNovo = termoAntigo * (-pow(x, 2)/((2*k)*(2*k+1)));
		somatoria += termoNovo;

		termoAntigo = termoNovo;
		k++;
	}while(termoAntigo < pow(10, -8));

	return somatoria;
}

int frac(float transp){
	int inteiro;

	inteiro = transp * 1;
}

int main(){
	float sen;
	int c1, c2;

	printf("x = ");
	scanf("%f", &sen);

	printf("Sen(%f) = %.8f", sen, senTaylor(sen));
}