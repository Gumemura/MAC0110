/*
Nome: Guilherme Umemura

nUSP: 9353592
*/

/*
TO DO LIST
	-PROBLEMAS
		- Rever textos!
		- PROBLEMA.1: se for inputado uma letra numa var tipo int, loop infinito

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

void tabuleiroVelha();
char s1 = ' ',s2 = ' ',s3 = ' ',s4 = ' ',s5 = ' ',s6 = ' ',s7 = ' ',s8 = ' ',s9 = ' ';
int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0;

int main(){
	int full1 = FALSE, full2 = FALSE, full3 = FALSE, full4 = FALSE, full5 = FALSE, full6 = FALSE, full7 = FALSE, full8 = FALSE, full9 = FALSE;
	//As variaveis 'full' verificam se já tem algum valor atribuido ao respectivo campo (exemplo: se full1 == true, isso que dizer que o campo 1 (linha 1 coluna 1) já tem um valor ('s' ou 'o'))
	int pontoN1 = FALSE, pontoN2 =  FALSE, pontoN3 =  FALSE, pontoN4 =  FALSE, pontoN5 =  FALSE, pontoN6 =  FALSE, pontoN7 =  FALSE, pontoN8 =  FALSE;
	//As variaveis pontoN# verificam se determinada combinacao ja foi pontuada
	
	int pontosPC = 0, pontosJogador = 0;
	int coluna, linha, podePedirLetra = TRUE;
	int numAleatorio, letraAleatoria, pcJaJogou = FALSE, contadorRodadas = 1, quemJogaPrimeiro;
	char inputSouO;

	//Print inicial do tabuleiro, apenas para introduzi-lo ao jogador
	printf("\n\t######### JOGO DO S.O.S. #########t\n\n");
	printf("\tOBJETIVO: Marcar pontos ao escrever SOS no tabuleiro\n");
	printf("\tREGRAS: Cada jogador escolhe, em seu turno, uma casa e atribui a ela a letra 'S' ou 'O'\n");
	printf("\tCOMO JOGAR: Digite as cordenadas do campo que quer alterar e. em seguida, a letra que quer inserir\n\n");
	printf("\tEXEMPLO: Se quiser alterar a casa de numero 6, insira linha 2 e coluna 3\n\n");
	printf("\t\t      COLUNAS\n");
	printf("\t\t     1   2   3\n\n");
	printf("\t\t1    %d ",1 ); printf("|"); printf(" %d ",2); printf("|"); printf(" %d \n",3);
	printf("\t\t    ---+---+---\n");
	printf("\tLINHAS\t2    %d ",4); printf("|"); printf(" %d ",5); printf("|"); printf(" %d \n",6);
	printf("\t\t    ---+---+---\n");
	printf("\t\t3    %d ",7); printf("|"); printf(" %d ",8); printf("|"); printf(" %d \n\n\n",9);

	printf("\tQuem voce quer que comece. Voce(0) ou o computador(1)?");
	scanf("%d", &quemJogaPrimeiro);
	printf("\n\n");

	do{
		printf("\t########### RODADA #%d ###########\n\n", contadorRodadas);
		printf("\t########### PLACAR ##############\n");
		printf("\tComputador: %d       Jogador: %d\n\n", pontosPC, pontosJogador);

		if(quemJogaPrimeiro == 0){
			//Aqui é pedido ao usuário que ele impute a linha
			do{
				printf("\tLinha (1 a 3): ");
				scanf("%d", &linha);
				printf("\n");
				if(linha <= 0 || linha >= 4){ //PROBLEMA.1 na checagem de numero: se for digiatado qualquer coisa que nao um numero, loop infinito
					printf("\tInserir valor entre 1 e 3 (existem apenas 3 linhas!)\n\n");
				}
			}while(linha <= 0 || linha >= 4);

			//Aqui é pedido ao usuário que ele impute a coluna
			do{
				printf("\tColuna (1 a 3): ");
				scanf("%d", &coluna);
				printf("\n");
				if(coluna <= 0 || coluna >= 4){ //PROBLEMA.1 na checagem de numero: se for digiatado qualquer coisa que nao um numero, loop infinito
					printf("\tInserir valor entre 1 e 3 (existem apenas 3 colunas!)\n\n");
				}else{
					//Nesse lógica é verificado se o campo no qual o suário quer inserir já tem um valor 
					if(linha == 1){
						if(coluna == 1 && full1 == TRUE)		{printf("\tValor ja preenchido!\n\n"); podePedirLetra = FALSE;}
						else if(coluna == 2 && full2 == TRUE)	{printf("\tValor ja preenchido!\n\n"); podePedirLetra = FALSE;}
						else if(coluna == 3 && full3 == TRUE)	{printf("\tValor ja preenchido!\n\n"); podePedirLetra = FALSE;}
						else {podePedirLetra = TRUE;}
					}
					else if(linha == 2){
						if(coluna == 1 && full4 == TRUE)		{printf("\tValor ja preenchido!\n\n"); podePedirLetra = FALSE;}
						else if(coluna == 2 && full5 == TRUE)	{printf("\tValor ja preenchido!\n\n"); podePedirLetra = FALSE;}
						else if(coluna == 3 && full6 == TRUE)	{printf("\tValor ja preenchido!\n\n"); podePedirLetra = FALSE;}
						else {podePedirLetra = TRUE;} 
					}
					else if(linha == 3){
						if(coluna == 1 && full7 == TRUE)		{printf("\tValor ja preenchido!\n\n"); podePedirLetra = FALSE;}
						else if(coluna == 2 && full8 == TRUE)	{printf("\tValor ja preenchido!\n\n"); podePedirLetra = FALSE;}
						else if(coluna == 3 && full9 == TRUE)	{printf("\tValor ja preenchido!\n\n"); podePedirLetra = FALSE;}
						else {podePedirLetra = TRUE;}
					}
				}
			}while(coluna <= 0 || coluna >= 4);
		}

		//A variavevel 'podePedirLetra' representa o seguinte: o usuário ja imputou um valor valido para a linha e para a coluna. Assim, pode prosseguir para inserir a letra
		if(podePedirLetra){
			if(quemJogaPrimeiro == 0){
				do{
					printf("\tLetra ('s' ou 'o'): ");
					scanf(" %c", &inputSouO);
					printf("\n");
					if(inputSouO != 's' && inputSouO != 'S' && inputSouO != 'o' && inputSouO != 'O'){
						printf("\tInserir a letra S ou O (maiusculo ou minusculo)\n\n"); 
					}
				}while(inputSouO != 's' && inputSouO != 'S' && inputSouO != 'o' && inputSouO != 'O');

				//Nesse lógica é verificado se o campo ja tem um valor atribuido e, se não, atribui o valor da letra imputada pelo usuario ao respectivo campo
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

				int valorAnteriorPontosJogador = pontosJogador;

				if(((n1 + n2 + n3) == 1 + 6 + 9) && pontoN1 == FALSE)			{pontosJogador++; pontoN1 = TRUE;}
				if(((n4 + n5 + n6) == 27 + 162 + 243) && pontoN2 == FALSE)		{pontosJogador++; pontoN2 = TRUE;}
				if(((n7 + n8 + n9) == 729 + 4374 + 6561) && pontoN3 == FALSE)	{pontosJogador++; pontoN3 = TRUE;}
				if(((n1 + n4 + n7) == 1 + 54 + 729) && pontoN4 == FALSE)		{pontosJogador++; pontoN4 = TRUE;}
				if(((n2 + n5 + n8) == 3 + 162 + 2187) && pontoN5 == FALSE)		{pontosJogador++; pontoN5 = TRUE;}
				if(((n3 + n6 + n9) == 9 + 486 + 6561) && pontoN6 == FALSE)		{pontosJogador++; pontoN6 = TRUE;}
				if(((n3 + n5 + n7) == 9 + 162 + 729) && pontoN7 == FALSE)		{pontosJogador++; pontoN7 = TRUE;}
				if(((n1 + n5 + n9) == 1 + 162 + 6561) && pontoN8 == FALSE)		{pontosJogador++; pontoN8 = TRUE;}

				printf("\n\n");
				if(valorAnteriorPontosJogador != pontosJogador){
					printf("\t\tPONTO PARA O JOGADOR!!!\n\n");
				}

				quemJogaPrimeiro = 1;
			}

			else if(quemJogaPrimeiro == 1){
				//Nessa lógica é feita a jogada do computador
				if(full1 == FALSE && full2 == FALSE && full3 == FALSE && full4 == FALSE && full5 == FALSE && full6 == FALSE && full7 == FALSE && full8 == FALSE && full9 == FALSE){
					printf("\n\tOla! Vamos jogar?");
				}else{
					printf("\n\tAgora e minha vez!");
				}

				if(full1 == FALSE || full2 == FALSE || full3 == FALSE || full4 == FALSE || full5 == FALSE || full6 == FALSE || full7 == FALSE || full8 == FALSE || full9 == FALSE){
					printf("\n\tAguarde, estou pensando na minha jogada.......\n");
					do{					
						srand(time(NULL));
						numAleatorio = rand()%9 + 1;
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

					printf("\n\tJa sei! Vou alterar a casa de numero %d", numAleatorio);
					printf("\n\tE vou colocar a letra ");
					if(letraAleatoria == 0){
						printf("s!");
					}else{
						printf("o!");
					}
					printf("\n");

					if(contadorRodadas != 9){
						printf("\tSua vez!\n\n");
					}
				}

				tabuleiroVelha();

				int valorAnteriorPontosPC = pontosPC;

				if(((n1 + n2 + n3) == 1 + 6 + 9) && pontoN1 == FALSE)			{pontosPC++; pontoN1 = TRUE;}
				if(((n4 + n5 + n6) == 27 + 162 + 243) && pontoN2 == FALSE)		{pontosPC++; pontoN2 = TRUE;}
				if(((n7 + n8 + n9) == 729 + 4374 + 6561) && pontoN3 == FALSE)	{pontosPC++; pontoN3 = TRUE;}
				if(((n1 + n4 + n7) == 1 + 54 + 729) && pontoN4 == FALSE)		{pontosPC++; pontoN4 = TRUE;}
				if(((n2 + n5 + n8) == 3 + 162 + 2187) && pontoN5 == FALSE)		{pontosPC++; pontoN5 = TRUE;}
				if(((n3 + n6 + n9) == 9 + 486 + 6561) && pontoN6 == FALSE)		{pontosPC++; pontoN6 = TRUE;}
				if(((n3 + n5 + n7) == 9 + 162 + 729) && pontoN7 == FALSE)		{pontosPC++; pontoN7 = TRUE;}
				if(((n1 + n5 + n9) == 1 + 162 + 6561) && pontoN8 == FALSE)		{pontosPC++; pontoN8 = TRUE;}

				if(valorAnteriorPontosPC != pontosPC){
					printf("\t\t\n\nPONTO PARA O COMPUTADOR!!!\n\n");
				}

				printf("\n\n");

				quemJogaPrimeiro = 0;
			}
		}

		pcJaJogou = FALSE;
		podePedirLetra = TRUE;
		contadorRodadas++;

	}while(s1 == ' ' || s2 == ' ' || s3 == ' ' || s4 == ' ' || s5 == ' ' || s6 == ' ' || s7 == ' ' || s8 == ' ' || s9 == ' '); 

	printf("\n\n");
	printf("\t############## PLACAR FINAL ##############\n\n");
	printf("\t\tJOGADOR: %d\n", pontosJogador);
	printf("\t\tCOMPUTADOR: %d\n\n\n", pontosPC);

	if(pontosJogador > pontosPC){
		printf("\t\tVitoria do Jogador!!\n");
	}else if(pontosJogador < pontosPC){
		printf("\t\tVitoria do Computador!!\n");
	}else{
		printf("\t\tEmpate!!\n");
	}
}

//Essa função printará o tabuleiro e setará os um valor numérico para cada casa a depender da letra que ela contiver
void tabuleiroVelha(){

	printf("\n");
	printf("\t\t %c ", s1); printf("|"); printf(" %c ", s2); printf("|"); printf(" %c \n", s3);
	printf("\t\t---+---+---\n");
	printf("\t\t %c ", s4); printf("|"); printf(" %c ", s5); printf("|"); printf(" %c \n", s6);
	printf("\t\t---+---+---\n");
	printf("\t\t %c ", s7); printf("|"); printf(" %c ", s8); printf("|"); printf(" %c \n", s9);
	
	if(s1 == ' '){n1 = 0;} 		else if(s1 == 's'){n1 = 1;} 	else if(s1 == 'o'){n1 = 2;}
	if(s2 == ' '){n2 = 0;} 		else if(s2 == 's'){n2 = 3;} 	else if(s2 == 'o'){n2 = 6;}
	if(s3 == ' '){n3 = 0;} 		else if(s3 == 's'){n3 = 9;} 	else if(s3 == 'o'){n3 = 18;}
	if(s4 == ' '){n4 = 0;} 		else if(s4 == 's'){n4 = 27;} 	else if(s4 == 'o'){n4 = 54;}
	if(s5 == ' '){n5 = 0;} 		else if(s5 == 's'){n5 = 81;} 	else if(s5 == 'o'){n5 = 162;}
	if(s6 == ' '){n6 = 0;} 		else if(s6 == 's'){n6 = 243;} 	else if(s6 == 'o'){n6 = 486;}
	if(s7 == ' '){n7 = 0;} 		else if(s7 == 's'){n7 = 729;} 	else if(s7 == 'o'){n7 = 1458;}
	if(s8 == ' '){n8 = 0;} 		else if(s8 == 's'){n8 = 2187;} 	else if(s8 == 'o'){n8 = 4374;}
	if(s9 == ' '){n9 = 0;} 		else if(s9 == 's'){n9 = 6561;} 	else if(s9 == 'o'){n9 = 13122;}
}