/*
Nome: Guilherme Umemura

nUSP: 9353592
*/

/*
TO DO LIST
	-PROBLEMAS
		- Rever textos!
		- Problema.1: se for inputado uma letra numa var tipo int, loop infinito

	-UPGRADES
		- Scanf da linha e coluna na mesma linha (pra agilizar o jogo)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

char s1 = ' ',s2 = ' ',s3 = ' ',s4 = ' ',s5 = ' ',s6 = ' ',s7 = ' ',s8 = ' ',s9 = ' ';
int tabuleiroVelha();
int aleatorio(int, int);

int main(){

	int full1 = FALSE, full2 = FALSE, full3 = FALSE, full4 = FALSE, full5 = FALSE, full6 = FALSE, full7 = FALSE, full8 = FALSE, full9 = FALSE, podePedirLetra = TRUE;
	int coluna, linha;
	int numAleatorio, letraAleatoria, pcJaJogou = FALSE, contadorRodadas = 1;
	char inputSouO;

	printf("\n\t#### JOGO DO S.O.S. ####\t\n\n");
	printf("\tDigite as cordenadas do campo que quer alterar, e a letra que quer inserir\n");
	printf("\t\t      COLUNAS\n");
	printf("\t\t     1   2   3\n\n");
	printf("\t\t1    %d ",1 ); printf("|"); printf(" %d ",2); printf("|"); printf(" %d \n",3);
	printf("\t\t    ---+---+---\n");
	printf("\tLINHAS\t2    %d ",4); printf("|"); printf(" %d ",5); printf("|"); printf(" %d \n",6);
	printf("\t\t    ---+---+---\n");
	printf("\t\t3    %d ",7); printf("|"); printf(" %d ",8); printf("|"); printf(" %d \n\n\n",9);

	do{
		printf("\t########### RODADA #%d ###########\n\n", contadorRodadas);
		do{
			printf("Linha (1 a 3): ");
			scanf("%d", &linha);
			printf("\n");
			if(linha <= 0 || linha >= 4){ //Problema.1 na checagem de numero: se for digiatado qualquer coisa que nao um numero, loop infinito
				printf("Inserir valor entre 1 e 3 (existem apenas 3 linhas!)\n\n");
			}
		}while(linha <= 0 || linha >= 4);

		do{
			printf("Coluna (1 a 3): ");
			scanf("%d", &coluna);
			printf("\n");
			if(coluna <= 0 || coluna >= 4){ //Problema.1 na checagem de numero: se for digiatado qualquer coisa que nao um numero, loop infinito
				printf("Inserir valor entre 1 e 3 (existem apenas 3 colunas!)\n\n");
			}else{
				if(linha == 1){
					if(coluna == 1 && full1 == TRUE)		{printf("Valor ja preenchido!\n\n"); podePedirLetra = FALSE;}
					else if(coluna == 2 && full2 == TRUE)	{printf("Valor ja preenchido!\n\n"); podePedirLetra = FALSE;}
					else if(coluna == 3 && full3 == TRUE)	{printf("Valor ja preenchido!\n\n"); podePedirLetra = FALSE;}
					else {podePedirLetra = TRUE;}
				}
				else if(linha == 2){
					if(coluna == 1 && full4 == TRUE)		{printf("Valor ja preenchido!\n\n"); podePedirLetra = FALSE;}
					else if(coluna == 2 && full5 == TRUE)	{printf("Valor ja preenchido!\n\n"); podePedirLetra = FALSE;}
					else if(coluna == 3 && full6 == TRUE)	{printf("Valor ja preenchido!\n\n"); podePedirLetra = FALSE;}
					else {podePedirLetra = TRUE;} 
				}
				else if(linha == 3){
					if(coluna == 1 && full7 == TRUE)		{printf("Valor ja preenchido!\n\n"); podePedirLetra = FALSE;}
					else if(coluna == 2 && full8 == TRUE)	{printf("Valor ja preenchido!\n\n"); podePedirLetra = FALSE;}
					else if(coluna == 3 && full9 == TRUE)	{printf("Valor ja preenchido!\n\n"); podePedirLetra = FALSE;}
					else {podePedirLetra = TRUE;}
				}
			}
		}while(coluna <= 0 || coluna >= 4);

		if(podePedirLetra){
			do{
				printf("Letra ('s' ou 'o'): ");
				scanf(" %c", &inputSouO);
				printf("\n");
				if(inputSouO != 's' && inputSouO != 'S' && inputSouO != 'o' && inputSouO != 'O'){
					printf("Inserir a letra S ou O (maiusculo ou minusculo)\n\n"); 
				}
			}while(inputSouO != 's' && inputSouO != 'S' && inputSouO != 'o' && inputSouO != 'O');

			if(linha == 1){
				if(coluna == 1 && full1 == FALSE)		{s1 = inputSouO; full1 = TRUE;}
				else if(coluna == 2 && full2 == FALSE)	{s2 = inputSouO; full2 = TRUE;}
				else if(coluna == 3 && full3 == FALSE)	{s3 = inputSouO; full3 = TRUE;}
			}
			else if(linha == 2){
				if(coluna == 1 && full4 == FALSE)		{s4 = inputSouO; full4 = TRUE;}
				else if(coluna == 2 && full5 == FALSE)	{s5 = inputSouO; full5 = TRUE;}
				else if(coluna == 3 && full6 == FALSE)	{s6 = inputSouO; full6 = TRUE;} 
			}
			else if(linha == 3){
				if(coluna == 1 && full7 == FALSE)		{s7 = inputSouO; full7 = TRUE;}
				else if(coluna == 2 && full8 == FALSE)	{s8 = inputSouO; full8 = TRUE;}
				else if(coluna == 3 && full9 == FALSE)	{s9 = inputSouO; full9 = TRUE;}
			}

			tabuleiroVelha();

			printf("\nAgora e minha vez!");
			printf("\nAguarde, estou pensando.......\n");

			if(full1 == FALSE || full2 == FALSE || full3 == FALSE || full4 == FALSE || full5 == FALSE || full6 == FALSE || full7 == FALSE || full8 == FALSE || full9 == FALSE){
				do{
					srand(time(NULL));
					numAleatorio = rand()%9 + 1;

					srand(time(NULL));
					letraAleatoria = rand()%2;

					if(numAleatorio == 1 && full1 == FALSE){
						if(letraAleatoria == 0){s1 = 's';}
						if(letraAleatoria == 1){s1 = 'o';}
						full1 = TRUE;
						pcJaJogou = TRUE;
					}
					else if(numAleatorio == 2 && full2 == FALSE){
						if(letraAleatoria == 0){s2 = 's';}
						if(letraAleatoria == 1){s2 = 'o';}
						full2 = TRUE;
						pcJaJogou = TRUE;
					}
					else if(numAleatorio == 3 && full3 == FALSE){
						if(letraAleatoria == 0){s3 = 's';}
						if(letraAleatoria == 1){s3 = 'o';}
						full3 = TRUE;
						pcJaJogou = TRUE;
					}
					else if(numAleatorio == 4 && full4 == FALSE){
						if(letraAleatoria == 0){s4 = 's';}
						if(letraAleatoria == 1){s4 = 'o';}
						full4 = TRUE;
						pcJaJogou = TRUE;
					}
					else if(numAleatorio == 5 && full5 == FALSE){
						if(letraAleatoria == 0){s5 = 's';}
						if(letraAleatoria == 1){s5 = 'o';}
						full5 = TRUE;
						pcJaJogou = TRUE;
					}
					else if(numAleatorio == 6 && full6 == FALSE){
						if(letraAleatoria == 0){s6 = 's';}
						if(letraAleatoria == 1){s6 = 'o';}
						full6 = TRUE;
						pcJaJogou = TRUE;
					}
					else if(numAleatorio == 7 && full7 == FALSE){
						if(letraAleatoria == 0){s7 = 's';}
						if(letraAleatoria == 1){s7 = 'o';}
						full7 = TRUE;
						pcJaJogou = TRUE;
					}
					else if(numAleatorio == 8 && full8 == FALSE){
						if(letraAleatoria == 0){s8 = 's';}
						if(letraAleatoria == 1){s8 = 'o';}
						full8 = TRUE;
						pcJaJogou = TRUE;
					}
					else if(numAleatorio == 9 && full9 == FALSE){
						if(letraAleatoria == 0){s9 = 's';}
						if(letraAleatoria == 1){s9 = 'o';}
						full9 = TRUE;
						pcJaJogou = TRUE;
					}
				}while(pcJaJogou == FALSE);

				printf("\nJa sei! Vou alterar a casa de numero %d", numAleatorio);
				printf("\nE vou colocar a seguinte letra ");
				if(letraAleatoria == 0){
					printf("s!");
				}else{
					printf("o!");
				}
				printf("\n");
			}
		}

		tabuleiroVelha();

		printf("\nSua vez!\n\n");

		pcJaJogou = FALSE;
		podePedirLetra = TRUE;
		contadorRodadas++;

	}while(s1 == ' ' || s2 == ' ' || s3 == ' ' || s4 == ' ' || s5 == ' ' || s6 == ' ' || s7 == ' ' || s8 == ' ' || s9 == ' '); 
}

int tabuleiroVelha(){
	//Print da tabela
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0;
	int somaCasas = n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9;

	printf("\n");
	printf("\t\t\t %c ", s1); printf("|"); printf(" %c ", s2); printf("|"); printf(" %c \n", s3);
	printf("\t\t\t---+---+---\n");
	printf("\t\t\t %c ", s4); printf("|"); printf(" %c ", s5); printf("|"); printf(" %c \n", s6);
	printf("\t\t\t---+---+---\n");
	printf("\t\t\t %c ", s7); printf("|"); printf(" %c ", s8); printf("|"); printf(" %c \n", s9);

	if(s1 == ' '){n1 = 0;} 		else if(s1 == 's'){n1 = 1;} 	else if(s1 == 'o'){n1 = 2;}
	if(s2 == ' '){n2 = 0;} 		else if(s2 == 's'){n2 = 3;} 	else if(s2 == 'o'){n2 = 6;}
	if(s3 == ' '){n3 = 0;} 		else if(s3 == 's'){n3 = 9;} 	else if(s3 == 'o'){n3 = 18;}
	if(s4 == ' '){n4 = 0;} 		else if(s4 == 's'){n4 = 27;} 	else if(s4 == 'o'){n4 = 54;}
	if(s5 == ' '){n5 = 0;} 		else if(s5 == 's'){n5 = 81;} 	else if(s5 == 'o'){n5 = 162;}
	if(s6 == ' '){n6 = 0;} 		else if(s6 == 's'){n6 = 243;} 	else if(s6 == 'o'){n6 = 486;}
	if(s7 == ' '){n7 = 0;} 		else if(s7 == 's'){n7 = 729;} 	else if(s7 == 'o'){n7 = 1458;}
	if(s8 == ' '){n8 = 0;} 		else if(s8 == 's'){n8 = 2187;} 	else if(s8 == 'o'){n8 = 4374;}
	if(s9 == ' '){n9 = 0;} 		else if(s9 == 's'){n9 = 6561;} 	else if(s9 == 'o'){n9 = 13122;}

	return(somaCasas);
}




