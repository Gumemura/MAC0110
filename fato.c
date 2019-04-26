/****************************************************************
    Nome: Guilherme Umemura
    NUSP: 9353592

    Fonte e comentários: 

****************************************************************/

#include <stdio.h>
#include <math.h>

double senTaylor(double x){
	int k = 1, sinal;
	/*double termoAntigo, termoNovo, somatoria;

	termoAntigo = x;
	somatoria = 0;

	do{
		termoNovo = termoAntigo * (-pow(x, 2)/((2*k)*((2*k)+1)));
		somatoria += termoNovo;

		termoAntigo = termoNovo;
		k++;
	}while(termoAntigo <= pow(10, -8));*/
	double numerador, denominador, somatoria;

	numerador = x;
	denominador = 1;
	somatoria = 0;

	while((numerador/denominador) >= pow(10, -8)){
		somatoria += (numerador/denominador) * sinal;

		sinal *= -1;
		numerador *= x * x;
		denominador *= ++k * (++k);
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

	printf("\n\n%f", sin(1));
	printf("\n\n%f", sin(2));
	printf("\n\n%f", sin(3));
	printf("\n\n%f", sin(4));
	printf("\n\n%f", sin(5));
	printf("\n\n%f", sin(6));
}