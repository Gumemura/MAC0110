/****************************************************************
    Nome: Guilherme Umemura
    NUSP: 9353592

    Fonte e comentários: 

****************************************************************/

#include <stdio.h>
#include <math.h>

double senTaylor(double x){
	int k = 1, sinal = 1;
	double numerador = x, denominador = 1, somatoria = 0;

	while((numerador/denominador) >= pow(10, -8)){
		somatoria += (numerador/denominador) * sinal;

		sinal *= -1;
		numerador *= x * x;
		denominador *= ++k;
		denominador *= ++k;
	}

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