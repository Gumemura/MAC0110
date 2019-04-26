/****************************************************************
    Nome: Guilherme Umemura
    NUSP: 9353592

    Fonte e comentários: 

****************************************************************/

#include <stdio.h>
#include <math.h>

double senTaylor(double x){
	int k = 1;
	double termoAntigo, termoNovo, somatoria;

	somatoria = x;
	termoAntigo = x;

	do{
		termoNovo = termoAntigo * (-pow(x, 2)/((2*k)*((2*k)+1)));
		somatoria += termoNovo;

		termoAntigo = termoNovo;
		k++;
	}while(termoAntigo <= pow(10, -11));

	return somatoria;
}

/*float modulo(float transp){
	if(transp < 0)
		transp *= -1;

	return transp;
}

float frac(float fracionaria){
	double store, param;

	store = modf(fracionaria, &param);

	return store;
}*/

int main(){
	double sen;
	//int c1, c2;

	printf("x = ");
	scanf("%lf", &sen);

	printf("Sen(%lf) = %.11lf", sen, senTaylor(sen));
}