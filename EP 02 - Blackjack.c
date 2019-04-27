/****************************************************************
    Nome: Guilherme Umemura
    NUSP: 9353592

    Fonte e comentários: 

****************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double seno(double sX){
	int k = 1, sinal = 1;
	double numerador = sX, denominador = 1, somatoria = 0;

	while((numerador/denominador) >= pow(10, -8)){
		somatoria += (numerador/denominador) * sinal;

		sinal *= -1;
		numerador *= sX * sX;
		denominador *= ++k;
		denominador *= ++k;
		//denominador *= ++k * (++k); Não funcionou :(
	}
	return somatoria;
}

float modulo(float transp){
	if(transp < 0)
		transp *= -1;

	return transp;
}

float frac(float fracionaria){
	double store, param;

	store = modf(fracionaria, &param) * pow(10, 6);

	return store;
}

int main(){
	double semente;
	int c1 = 745165, c2 = 55454665, iteracoes;

	printf("\nSemente (0 < n < 1) = ");
	scanf("%lf", &semente);

	printf("Iteracoes = ");
	scanf("%d", &iteracoes);
	printf("\n");

	srand(frac(c1 * modulo(seno(semente)) + c2));

	int carta, pontosMesa = 0, contadorVitoriaMesa = 0;
	float porcentagem, num, den;

	for(int pontosJogador = 12; pontosJogador < 21; pontosJogador++){
		for(int i = 0; i < iteracoes; i++){
			do{
				carta = rand() % 12 + 1;

				if(carta == 1)
					pontosMesa += 1;
				else if(carta == 2)
					pontosMesa += 2;
				else if(carta == 3)
					pontosMesa += 3;
				else if(carta == 4)
					pontosMesa += 4;
				else if(carta == 5)
					pontosMesa += 5;
				else if(carta == 6)
					pontosMesa += 6;
				else if(carta == 7)
					pontosMesa += 7;
				else if(carta == 8)
					pontosMesa += 8;
				else if(carta == 9)
					pontosMesa += 9;
				else if(carta == 10 || carta == 11 || carta == 12 || carta == 13)
					pontosMesa += 10;
			}while(pontosMesa <= pontosJogador);

			if(pontosMesa <= 21 && pontosMesa > pontosJogador)
				contadorVitoriaMesa++;

			pontosMesa = 0;
		}
		num = contadorVitoriaMesa;
		den = iteracoes;
		porcentagem = (num/den) * 100;

		printf("%d ( %.2f%c): ", pontosJogador, porcentagem, '%');
		while(porcentagem - 2 > 0){
			printf("*");
			porcentagem -= 2;
		}
		printf("\n");

		contadorVitoriaMesa = 0;
	}
}