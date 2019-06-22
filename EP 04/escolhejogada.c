/****************************************************************
    Nome: Guilherme Umemura
    NUSP: 9353592

    Fonte e comentários: 


		 7	0	1
		  \ | /
	    6 —	  — 2
		  / | \ 
         5  4  3

****************************************************************/


#include <stdio.h>

#define LIMITE 8
#define MAX 64
#define TRUE 1
#define FALSE 0
#define JOGADOR 1
#define IA 0

void escolhejogada(int tabuleiro[8][8], int cor, int *linha, int *coluna){
	int linhaAnalise, colAnalise, cPI = 0, aPJ[3][MAX], cPJ = 0, pC = FALSE;

	*linha = -1;
	*coluna = -1;
	//cPI = contador peças inimigas (conta quantas peças inimigas tem na sequencia analisada)
	//aPJ = armazem possiveis jogadas (em cada coluna há ters infos: a linha, coluna e quantidade de pontos q cada possivel jogada vai mudar)
		//aPJ[0] = linha
		//aPJ[1] = coluna
		//aPJ[0] = pontos
	//cPJ = coluna possiveis jogadas (serve para indexar a coluna da matriz onde serao armazenadas as possiveis jogadas)
	//pC = pode contabilizar (serve para dizer que a sequencia de peças analisadas é um jogada valida, ou seja, a sequencia começa com uma peça da cor do computador, é seguida por peças inimigas, e termina com um campo vazio)

	int verificaVetor(int linhaCompara, int colCompara, int vectorCompara[3][MAX]){
		//Esse função verifica se ja existe um par de coordenadas (linha x coluna) dentro do vetor aPJ (armazem possiveis jogadas)
		int ret = -1;

		for(int c = 0; c < MAX; c++){
			if(vectorCompara[0][c] == linhaCompara){
				if(vectorCompara[1][c] == colCompara){
					ret = c;
					break;
				}
			}
		}
		return ret;
	}

	for(int linReseta = 0; linReseta < 3; linReseta++){
		for (int colReseta = 0; colReseta < MAX; colReseta++){
			//Aqui os valores do vetor são resetados antes de serem inicializados para um valor impossivel de ser estabelecido no meio do codigo (-1)
			aPJ[linReseta][colReseta] = -1;
		}
	}
	
	for(int lin = 0; lin < 8; lin++){
		for (int col = 0; col < 8; col++){
			/*Aqui são solhidas as coordenadas das possiveis jogadas, bem como a respectiva pontuação que a IA ganhará caso jogue em determinada coordenada
			As possiveis jogadas sao armazenadas no vetor aPJ, vide legenda das variaveis acima. aPJ tem tres linhas: as duas primeiras armazenam as coordenadas da possivel jogada (na linha 0, as coordenadas da linha, e na 1, as coordenadas da coluna). Na linha 2, a ultima, é armazenado a quantidade de pontos que a IA ganhara caso jogue nessa coordenada 
			A busca pelas possiveis jogadas é feita aqui dentro desses for, e é feita da seguitne maneira:
				1. É analisada casa por casa. Caso nela contenha o valor da cor da IA, prossefue-se para a etapa seguinte
				2. Após localizada uma casa que tenha a cor da IA, são analisadas todas as direções a partir dessa casa, conforme esquema abaixo

						7	0	1
						  \ | /
						6 —	  — 2
						  / | \ 
						 5  4  3

				3. Caso se encontre uma sequencia de valida, a coordenada da possicao onde pode ser feita a jogada é armazenada no vetor aPJ, bem como a pontuação que essa jogada acarretaria
				4. Depois, sao analisados todos os elemementos de aPJ e seleciona-se a coordenada com a maior pontuação*/
			if(tabuleiro[lin][col] == cor){
				for(int sentidoNS = 0; sentidoNS < LIMITE; sentidoNS++){
					//Norte
					if(sentidoNS == 0){

						linhaAnalise = lin - 1;

						if(tabuleiro[linhaAnalise][col] == (cor * -1)){
							for(linhaAnalise = lin - 1; linhaAnalise >= 0; linhaAnalise--){
								if(tabuleiro[linhaAnalise][col] == (cor * -1)){
									cPI++;
								}else if(tabuleiro[linhaAnalise][col] == 0){
									if(cPI > 0)
										pC = TRUE;	
									break;
								}else{
									break;
								}
							}

							if(pC == TRUE){
								if(linhaAnalise >= 0){
									if(verificaVetor(linhaAnalise, col, aPJ) == -1){
										aPJ[0][cPJ] = linhaAnalise;
										aPJ[1][cPJ] = col;
										aPJ[2][cPJ] = cPI;
										cPJ++;
									}else{
										aPJ[2][verificaVetor(linhaAnalise, col, aPJ)] += cPI;
									}
								}
							}
						}

						cPI = 0;
						pC = FALSE;
					}

					//Nordeste
					if(sentidoNS == 1){
						linhaAnalise = lin - 1;
						colAnalise = col + 1;

						if(tabuleiro[linhaAnalise][colAnalise] == (cor * -1)){
							while(linhaAnalise >= 0 && colAnalise < 8){
								if(tabuleiro[linhaAnalise][colAnalise] == (cor * -1)){
									cPI++;
								}else if(tabuleiro[linhaAnalise][colAnalise] == 0){
									if(cPI > 0)
										pC = TRUE;	
									break;
								}else{
									break;
								}
								linhaAnalise--;
								colAnalise++;
							}

							if(pC == TRUE){
								if(linhaAnalise >= 0 && colAnalise < 8){
									if(verificaVetor(linhaAnalise, colAnalise, aPJ) == -1){
										aPJ[0][cPJ] = linhaAnalise;
										aPJ[1][cPJ] = colAnalise;
										aPJ[2][cPJ] = cPI;
										cPJ++;
									}else{
										aPJ[2][verificaVetor(linhaAnalise, colAnalise, aPJ)] += cPI;
									}
								}
							}
						}

						cPI = 0;
						pC = FALSE;
					}

					//Leste
					if(sentidoNS == 2){
						colAnalise = col + 1;

						if(tabuleiro[lin][colAnalise] == (cor * -1)){
							for(colAnalise = col + 1; colAnalise < 8; colAnalise++){
								if(tabuleiro[lin][colAnalise] == (cor * -1)){
									cPI++;
								}else if(tabuleiro[lin][colAnalise] == 0){
									if(cPI > 0)
										pC = TRUE;	
									break;
								}else{
									break;
								}
							}

							if(pC == TRUE){
								if(colAnalise < 8){
									if(verificaVetor(lin, colAnalise, aPJ) == -1){
										aPJ[0][cPJ] = lin;
										aPJ[1][cPJ] = colAnalise;
										aPJ[2][cPJ] = cPI;
										cPJ++;
									}else{
										aPJ[2][verificaVetor(lin, colAnalise, aPJ)] += cPI;
									}
								}
							}
						}

						cPI = 0;
						pC = FALSE;
					}

					//Sudeste
					if(sentidoNS == 3){
						linhaAnalise = lin + 1;
						colAnalise = col + 1;

						if(tabuleiro[linhaAnalise][colAnalise] == (cor * -1)){
							while(linhaAnalise < 8 && colAnalise < 8){
								if(tabuleiro[linhaAnalise][colAnalise] == (cor * -1)){
									cPI++;
								}else if(tabuleiro[linhaAnalise][colAnalise] == 0){
									if(cPI > 0)
										pC = TRUE;	
									break;
								}else{
									break;
								}
								linhaAnalise++;
								colAnalise++;
							}

							if(pC == TRUE){
								if(linhaAnalise < 8 && colAnalise < 8){
									if(verificaVetor(linhaAnalise, colAnalise, aPJ) == -1){
										aPJ[0][cPJ] = linhaAnalise;
										aPJ[1][cPJ] = colAnalise;
										aPJ[2][cPJ] = cPI;
										cPJ++;
									}else{
										aPJ[2][verificaVetor(linhaAnalise, colAnalise, aPJ)] += cPI;
									}
								}
							}
						}

						cPI = 0;
						pC = FALSE;
					}

					//Sul
					if(sentidoNS == 4){
						linhaAnalise = lin + 1;

						if(tabuleiro[linhaAnalise][col] == (cor * -1)){
							for(linhaAnalise = lin + 1; linhaAnalise < 8; linhaAnalise++){
								if(tabuleiro[linhaAnalise][col] == (cor * -1)){
									cPI++;
								}else if(tabuleiro[linhaAnalise][col] == 0){
									if(cPI > 0)
										pC = TRUE;	
									break;
								}else{
									break;
								}
							}

							if(pC == TRUE){
								if(linhaAnalise < 8){
									if(verificaVetor(linhaAnalise, col, aPJ) == -1){
										aPJ[0][cPJ] = linhaAnalise;
										aPJ[1][cPJ] = col;
										aPJ[2][cPJ] = cPI;
										cPJ++;
									}else{
										aPJ[2][verificaVetor(linhaAnalise, col, aPJ)] += cPI;
									}
								}
							}
						}

						cPI = 0;
						pC = FALSE;
					}

					//Sudoeste
					if(sentidoNS == 5){
						linhaAnalise = lin + 1;
						colAnalise = col - 1;

						if(tabuleiro[linhaAnalise][colAnalise] == (cor * -1)){
							while(linhaAnalise < 8 && colAnalise >= 0){
								if(tabuleiro[linhaAnalise][colAnalise] == (cor * -1)){
									cPI++;
								}else if(tabuleiro[linhaAnalise][colAnalise] == 0){
									if(cPI > 0)
										pC = TRUE;	
									break;
								}else{
									break;
								}
								linhaAnalise++;
								colAnalise--;
							}

							if(pC == TRUE){
								if(linhaAnalise < 8 && colAnalise >= 0){
									if(verificaVetor(linhaAnalise, colAnalise, aPJ) == -1){
										aPJ[0][cPJ] = linhaAnalise;
										aPJ[1][cPJ] = colAnalise;
										aPJ[2][cPJ] = cPI;
										cPJ++;
									}else{
										aPJ[2][verificaVetor(linhaAnalise, colAnalise, aPJ)] += cPI;
									}
								}
							}
						}

						cPI = 0;
						pC = FALSE;
					}

					//Oeste
					if(sentidoNS == 6){
						colAnalise = col - 1;

						if(tabuleiro[lin][colAnalise] == (cor * -1)){
							for(colAnalise = col - 1; colAnalise >= 0; colAnalise--){
								if(tabuleiro[lin][colAnalise] == (cor * -1)){
									cPI++;
								}else if(tabuleiro[lin][colAnalise] == 0){
									if(cPI > 0)
										pC = TRUE;	
									break;
								}else{
									break;
								}
							}

							if(pC == TRUE){
								if(colAnalise >= 0){
									if(verificaVetor(lin, colAnalise, aPJ) == -1){
										aPJ[0][cPJ] = lin;
										aPJ[1][cPJ] = colAnalise;
										aPJ[2][cPJ] = cPI;
										cPJ++;
									}else{
										aPJ[2][verificaVetor(lin, colAnalise, aPJ)] += cPI;
									}
								}
							}
						}

						cPI = 0;
						pC = FALSE;
					}

					//Noroeste
					if(sentidoNS == 7){
						linhaAnalise = lin - 1;
						colAnalise = col - 1;

						if(tabuleiro[linhaAnalise][colAnalise] == (cor * -1)){
							while(linhaAnalise >= 0 && colAnalise >= 0){
								if(tabuleiro[linhaAnalise][colAnalise] == (cor * -1)){
									cPI++;
								}else if(tabuleiro[linhaAnalise][colAnalise] == 0){
									if(cPI > 0)
										pC = TRUE;	
									break;
								}else{
									break;
								}
								linhaAnalise--;
								colAnalise--;
							}

							if(pC == TRUE){
								if(linhaAnalise >= 0 && colAnalise >= 0){
									if(verificaVetor(linhaAnalise, colAnalise, aPJ) == -1){
										aPJ[0][cPJ] = linhaAnalise;
										aPJ[1][cPJ] = colAnalise;
										aPJ[2][cPJ] = cPI;
										cPJ++;
									}else{
										aPJ[2][verificaVetor(linhaAnalise, colAnalise, aPJ)] += cPI;
									}
								}
							}
						}

						cPI = 0;
						pC = FALSE;
					}
				}
			}
		}
	}

	int maiorValor = 0;
	for(int sp = 0; sp < MAX; sp++){
		//dentro dese 'for' vamos atribuir valor a *linha e *coluna com base no 3º elemento de aPJ (aPJ[2]), ou seja, com base nos pontos
		if(aPJ[2][sp] > maiorValor){
			*linha = aPJ[0][sp];
			*coluna = aPJ[1][sp];
			maiorValor = aPJ[2][sp];
		}
	}
}

int podejogar(int tabuleiro[8][8], int cor, int l, int c){
	int jogadaValida = 0;

	int lApj, cApj, contadorPJ = 0;
	//lApj = Linha analise pode jogar
	//cApj = coluna analise pode jogar

	if(tabuleiro[l][c] == 0){
		for(int pjNS = 0; pjNS < 8; pjNS++){
			//Norte
			if(pjNS == 0){
				lApj = l - 1;
				if(tabuleiro[lApj][c] == (cor * -1)){
					for(lApj = l - 1; lApj >= 0; lApj--){
						if(tabuleiro[lApj][c] == (cor * -1)){
							contadorPJ++;
						}else if(tabuleiro[lApj][c] == 0){
							break;
						}else{
							if(contadorPJ > 0)
								jogadaValida = 1;
							break;
						}
					}
				}
				contadorPJ = 0;
			}


			//Nordeste
			if(pjNS == 1){
				lApj = l - 1;
				cApj = c + 1;

				if(tabuleiro[lApj][cApj] == (cor * -1)){
					while(lApj >= 0 && cApj < 8){
						if(tabuleiro[lApj][cApj] == (cor * -1)){
							contadorPJ++;
						}else if(tabuleiro[lApj][cApj] == 0){
							break;
						}else{
							if(contadorPJ > 0)
								jogadaValida = 1;
							break;
						}
						lApj--;
						cApj++;
					}
				}
				contadorPJ = 0;
			}

			//Leste
			if(pjNS == 2){
				cApj = c + 1;
				if(tabuleiro[l][cApj] == (cor * -1)){
					for(cApj = c + 1; cApj < 8; cApj++){
						if(tabuleiro[l][cApj] == (cor * -1)){
							contadorPJ++;
						}else if(tabuleiro[l][cApj] == 0){
							break;
						}else{
							if(contadorPJ > 0)
								jogadaValida = 1;	
							break;
						}
					}
				}
				contadorPJ = 0;
			}

			//Sudeste
			if(pjNS == 3){
				lApj = l + 1;
				cApj = c + 1;

				if(tabuleiro[lApj][cApj] == (cor * -1)){
					while(lApj < 8 && cApj < 8){
						if(tabuleiro[lApj][cApj] == (cor * -1)){
							contadorPJ++;
						}else if(tabuleiro[lApj][cApj] == 0){
							break;
						}else{
							if(contadorPJ > 0)
								jogadaValida = 1;	
							break;
						}
						lApj++;
						cApj++;
					}
				}
				contadorPJ = 0;
			}

			//Sul
			if(pjNS == 4){
				lApj = l + 1;

				if(tabuleiro[lApj][c] == (cor * -1)){
					for(lApj = l + 1; lApj < 8; lApj++){
						if(tabuleiro[lApj][c] == (cor * -1)){
							contadorPJ++;
						}else if(tabuleiro[lApj][c] == 0){
							break;
						}else{
							if(contadorPJ > 0)
								jogadaValida = 1;	
							break;
						}
					}
				}
				contadorPJ = 0;
			}

			//Sudoeste
			if(pjNS == 5){
				lApj = l + 1;
				cApj = c - 1;

				if(tabuleiro[lApj][cApj] == (cor * -1)){
					while(lApj < 8 && cApj >= 0){
						if(tabuleiro[lApj][cApj] == (cor * -1)){
							contadorPJ++;
						}else if(tabuleiro[lApj][cApj] == 0){
							break;
						}else{
							if(contadorPJ > 0)
								jogadaValida = 1;	
							break;
						}
						lApj++;
						cApj--;
					}
				}
				contadorPJ = 0;
			}

			//Oeste
			if(pjNS == 6){
				cApj = c - 1;

				if(tabuleiro[l][cApj] == (cor * -1)){
					for(cApj = c - 1; cApj >= 0; cApj--){
						if(tabuleiro[l][cApj] == (cor * -1)){
							contadorPJ++;
						}else if(tabuleiro[l][cApj] == 0){
							break;
						}else{
							if(contadorPJ > 0)
								jogadaValida = 1;	
							break;
						}
					}
				}
				contadorPJ = 0;
			}

			//Noroeste
			if(pjNS == 7){
				lApj = l - 1;
				cApj = c - 1;

				if(tabuleiro[lApj][cApj] == (cor * -1)){
					while(lApj >= 0 && cApj >= 0){
						if(tabuleiro[lApj][cApj] == (cor * -1)){
							contadorPJ++;
						}else if(tabuleiro[lApj][cApj] == 0){
							break;
						}else{
							if(contadorPJ > 0)
								jogadaValida = 1;	
							break;
						}
						lApj--;
						cApj--;
					}
				}
				contadorPJ = 0;
			}
		}
	}
	return jogadaValida;
}

void printaTabuleiro(int a[8][8]){
	char v[8][8];

	for (int linhaConverte = 0; linhaConverte < 8; linhaConverte++){
		for (int colunaConverte = 0; colunaConverte < 8; colunaConverte++){
			//Aqui é feita a conversao dos elementos do vetor de numeros para letra, com o intuito de melhorar a visibilidade
			if(a[linhaConverte][colunaConverte] == 0){
				v[linhaConverte][colunaConverte] = ' ';
			}else if(a[linhaConverte][colunaConverte] == 1){
				v[linhaConverte][colunaConverte] = 'O';
			}else{
				v[linhaConverte][colunaConverte] = 'X';
			}
		}
	}

	printf("\n\t\t 0   1   2   3   4   5   6   7\n\n");
	printf("\t0\t %c ", v[0][0]); printf("|"); printf(" %c ", v[0][1]); printf("|"); printf(" %c ", v[0][2]); printf("|"); printf(" %c ", v[0][3]); printf("|"); printf(" %c ", v[0][4]); printf("|"); printf(" %c ", v[0][5]); printf("|"); printf(" %c ", v[0][6]); printf("|"); printf(" %c \n", v[0][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t1\t %c ", v[1][0]); printf("|"); printf(" %c ", v[1][1]); printf("|"); printf(" %c ", v[1][2]); printf("|"); printf(" %c ", v[1][3]); printf("|"); printf(" %c ", v[1][4]); printf("|"); printf(" %c ", v[1][5]); printf("|"); printf(" %c ", v[1][6]); printf("|"); printf(" %c \n", v[1][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t2\t %c ", v[2][0]); printf("|"); printf(" %c ", v[2][1]); printf("|"); printf(" %c ", v[2][2]); printf("|"); printf(" %c ", v[2][3]); printf("|"); printf(" %c ", v[2][4]); printf("|"); printf(" %c ", v[2][5]); printf("|"); printf(" %c ", v[2][6]); printf("|"); printf(" %c \n", v[2][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t3\t %c ", v[3][0]); printf("|"); printf(" %c ", v[3][1]); printf("|"); printf(" %c ", v[3][2]); printf("|"); printf(" %c ", v[3][3]); printf("|"); printf(" %c ", v[3][4]); printf("|"); printf(" %c ", v[3][5]); printf("|"); printf(" %c ", v[3][6]); printf("|"); printf(" %c \n", v[3][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t4\t %c ", v[4][0]); printf("|"); printf(" %c ", v[4][1]); printf("|"); printf(" %c ", v[4][2]); printf("|"); printf(" %c ", v[4][3]); printf("|"); printf(" %c ", v[4][4]); printf("|"); printf(" %c ", v[4][5]); printf("|"); printf(" %c ", v[4][6]); printf("|"); printf(" %c \n", v[4][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t5\t %c ", v[5][0]); printf("|"); printf(" %c ", v[5][1]); printf("|"); printf(" %c ", v[5][2]); printf("|"); printf(" %c ", v[5][3]); printf("|"); printf(" %c ", v[5][4]); printf("|"); printf(" %c ", v[5][5]); printf("|"); printf(" %c ", v[5][6]); printf("|"); printf(" %c \n", v[5][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t6\t %c ", v[6][0]); printf("|"); printf(" %c ", v[6][1]); printf("|"); printf(" %c ", v[6][2]); printf("|"); printf(" %c ", v[6][3]); printf("|"); printf(" %c ", v[6][4]); printf("|"); printf(" %c ", v[6][5]); printf("|"); printf(" %c ", v[6][6]); printf("|"); printf(" %c \n", v[6][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t7\t %c ", v[7][0]); printf("|"); printf(" %c ", v[7][1]); printf("|"); printf(" %c ", v[7][2]); printf("|"); printf(" %c ", v[7][3]); printf("|"); printf(" %c ", v[7][4]); printf("|"); printf(" %c ", v[7][5]); printf("|"); printf(" %c ", v[7][6]); printf("|"); printf(" %c \n", v[7][7]);
	printf("\n\n");
}

void joga(int tabuleiro[8][8], int cor, int l, int c){
	int lJ, cJ, contadorJoga = 0, aquiMesmo = FALSE;

	for(int jNS = 0; jNS < 8; jNS++){
		//Norte
		if(jNS == 0){
			lJ = l - 1;
			if(tabuleiro[lJ][c] == (cor * -1)){
				for(lJ = l - 1; lJ >= 0; lJ--){
					if(tabuleiro[lJ][c] == (cor * -1)){
						contadorJoga++;
					}else if(tabuleiro[lJ][c] == cor){
						if(contadorJoga > 0)
							aquiMesmo = TRUE;
						break;
					}else{
						break;
					}
				}
			}

			if(aquiMesmo == TRUE){
				for(int trocaL = lJ + 1; trocaL <= l; trocaL++){
					tabuleiro[trocaL][c] = cor;
				}
			}

			contadorJoga = 0;
			aquiMesmo = FALSE;
		}

		//Nordeste
		if(jNS == 1){
			lJ = l - 1;
			cJ = c + 1;

			if(tabuleiro[lJ][cJ] == (cor * -1)){
				while(lJ >= 0 && cJ < 8){
					if(tabuleiro[lJ][cJ] == (cor * -1)){
						contadorJoga++;
					}else if(tabuleiro[lJ][cJ] == cor){
						if(contadorJoga > 0)
							aquiMesmo = TRUE;
						break;
					}else{
						break;
					}
					lJ--;
					cJ++;
				}

				if(aquiMesmo == TRUE){
					lJ += 1;
					cJ -= 1;
					for(int q = 0; q <= contadorJoga; q++){
						tabuleiro[lJ][cJ] = cor;
						lJ++;
						cJ--;
					}
				}
			}
			contadorJoga = 0;
			aquiMesmo = FALSE;
		}

		//Leste
		if(jNS == 2){
			cJ = c + 1;
			if(tabuleiro[l][cJ] == (cor * -1)){
				for(cJ = c + 1; cJ < 8; cJ++){
					if(tabuleiro[l][cJ] == (cor * -1)){
						contadorJoga++;
					}else if(tabuleiro[l][cJ] == cor){
						if(contadorJoga > 0)
							aquiMesmo = TRUE;	
						break;
					}else{
						break;
					}
				}
				if(aquiMesmo == TRUE){
					cJ -= 1;
					for(int trocaC = cJ; trocaC >= c; trocaC--)
						tabuleiro[l][trocaC] = cor;
				}
			}
			contadorJoga = 0;
			aquiMesmo = FALSE;
		}

		//Sudeste
		if(jNS == 3){
			lJ = l + 1;
			cJ = c + 1;

			if(tabuleiro[lJ][cJ] == (cor * -1)){
				while(lJ < 8 && cJ < 8){
					if(tabuleiro[lJ][cJ] == (cor * -1)){
						contadorJoga++;
					}else if(tabuleiro[lJ][cJ] == cor){
						if(contadorJoga > 0)
							aquiMesmo = TRUE;	
						break;
					}else{
						break;
					}
					lJ++;
					cJ++;
				}

				if(aquiMesmo == TRUE){
					lJ -= 1;
					cJ -= 1;

					for(int q = 0; q <= contadorJoga; q++){
						tabuleiro[lJ][cJ] = cor;
						lJ--;
						cJ--;
					}
				}
			}
			contadorJoga = 0;
			aquiMesmo = FALSE;
		}

		//Sul
		if(jNS == 4){
			lJ = l + 1;

			if(tabuleiro[lJ][c] == (cor * -1)){
				for(lJ = l + 1; lJ < 8; lJ++){
					if(tabuleiro[lJ][c] == (cor * -1)){
						contadorJoga++;
					}else if(tabuleiro[lJ][c] == cor){
						if(contadorJoga > 0)
							aquiMesmo = TRUE;
						break;
					}else{
						break;
					}
				}

				if(aquiMesmo == TRUE){
					lJ -= 1;
					for(int qSUL = 0; qSUL <= contadorJoga; qSUL++){
						tabuleiro[lJ][c] = cor;
						lJ--;
					}
				}
			}
			contadorJoga = 0;
			aquiMesmo = FALSE;
		}

		//Sudoeste
		if(jNS == 5){
			lJ = l + 1;
			cJ = c - 1;

			if(tabuleiro[lJ][cJ] == (cor * -1)){
				while(lJ < 8 && cJ >= 0){
					if(tabuleiro[lJ][cJ] == (cor * -1)){
						contadorJoga++;
					}else if(tabuleiro[lJ][cJ] == cor){
						if(contadorJoga > 0)
							aquiMesmo = TRUE;	
						break;
					}else{
						break;
					}
					lJ++;
					cJ--;
				}

				if(aquiMesmo == TRUE){
					lJ -= 1;
					cJ += 1;

					for(int q = 0; q <= contadorJoga; q++){
						tabuleiro[lJ][cJ] = cor;
						lJ--;
						cJ++;
					}

				}
			}

			contadorJoga = 0;
			aquiMesmo = FALSE;
		}

		//Oeste
		if(jNS == 6){
			cJ = c - 1;

			if(tabuleiro[l][cJ] == (cor * -1)){
				for(cJ = c - 1; cJ >= 0; cJ--){
					if(tabuleiro[l][cJ] == (cor * -1)){
						contadorJoga++;
					}else if(tabuleiro[l][cJ] == cor){
						if(contadorJoga > 0)
							aquiMesmo = TRUE;	
						break;
					}else{
						break;
					}
				}

				if(aquiMesmo == TRUE){
					cJ += 1;
					for(int trocaC = cJ; trocaC <= c; trocaC++)
						tabuleiro[l][trocaC] = cor;
				}
			}
			contadorJoga = 0;
			aquiMesmo = FALSE;
		}

		//Noroeste
		if(jNS == 7){
			lJ = l - 1;
			cJ = c - 1;

			if(tabuleiro[lJ][cJ] == (cor * -1)){
				while(lJ >= 0 && cJ >= 0){
					if(tabuleiro[lJ][cJ] == (cor * -1)){
						contadorJoga++;
					}else if(tabuleiro[lJ][cJ] == cor){
						if(contadorJoga > 0)
							aquiMesmo = TRUE;	
						break;
					}else{
						break;
					}
					lJ--;
					cJ--;
				}

				if(aquiMesmo == TRUE){
					lJ += 1;
					cJ += 1;
					for(int q = 0; q <= contadorJoga; q++){
						tabuleiro[lJ][cJ] = cor;
						lJ++;
						cJ++;
					}
				}


			}
			contadorJoga = 0;
			aquiMesmo = FALSE;
		}
	}
}

int main(){
	int tabJogo[8][8], linhaMuda = 0, colMuda = 0;

	int corJogador, corIA, contadorRodadas = 1, quemJogaAgora, semJogadaValida = 0, fimDeJogo = FALSE;

	int linhaJogada, colJogada;
	int lVstj, cVstj;
	int pontosPreta = 2, pontosBranco = 2;
	//lVstj = linha verifica se tem jogada. verifica se existem jogada valida
	//cVstj = coluna verifica se tem jogada

	for(int q = 0; q < 8; q++){
		for (int w = 0; w < 8; w++){
			//Resetando todas as casas do tabuleiro
			tabJogo[q][w] = 0;
		}
	}

	tabJogo[3][3] = 1;
	tabJogo[4][4] = 1;

	tabJogo[3][4] = -1;
	tabJogo[4][3] = -1;

	printf("\n\t\t---------- REVERSI ----------\n\n");
	printaTabuleiro(tabJogo);

	printf("\nEscolha sua cor (1 para branco ou -1 para pretas): ");
	scanf("%d", &corJogador);

	while(corJogador != 1 && corJogador != -1){
		printf("Numero invalido! Insira 1 para branco ou -1 para pretas): ");
		scanf("%d", &corJogador);
	}

	corIA = corJogador * -1;

	if(corJogador == -1)
		printf("\n\nVamos comecar! Como voce escolheu as pretas, voce comeca");
	else
		printf("\n\nVamos comecar! Como o computador joga com as pecas pretas, ele começa!");

	printf("\nObs.: No tabuleiro, as pecas brancas sao representadas por 'O', e as pretas por 'X'\n\n");

	//printaTabuleiro(tabJogo);

	if(-1 == corJogador){
		quemJogaAgora = JOGADOR;
		printaTabuleiro(tabJogo);
	}else
		quemJogaAgora = IA;

	while(fimDeJogo == FALSE){
		printf("\t############## RODADA %d ###############\n", contadorRodadas);
		printf("\t    PRETAS: %d               BRANCAS: %d\n\n", pontosPreta, pontosBranco);
		if(quemJogaAgora == JOGADOR){
			escolhejogada(tabJogo, corJogador, &lVstj, &cVstj);

			if(lVstj != -1 && cVstj != -1){
				printf("\tInsira as coordenadas da sua jogada (linha e coluna, respectivamente): ");
				scanf("%d %d", &linhaJogada, &colJogada);

				if(podejogar(tabJogo, corJogador, linhaJogada, colJogada) == 0/*jogada invalida*/){
					printf("\nJOGADA INVALIDA PERDEU\n");
					fimDeJogo = TRUE;
				}else{
					joga(tabJogo, corJogador, linhaJogada, colJogada);
				}
			}else{
				printf("\tSem jogadas validas :(");
				semJogadaValida++;		
				if(semJogadaValida > 1){
					fimDeJogo = TRUE;
				}
			}
			quemJogaAgora = IA;

			printaTabuleiro(tabJogo);
		}
		if(quemJogaAgora == IA){
			escolhejogada(tabJogo, corIA, &linhaMuda, &colMuda);

			if(linhaMuda != -1 && colMuda != -1){
				printf("\n\tJogada da IA:\n\t\tLinhas: %d\n\t\tColuna: %d\n", linhaMuda, colMuda);
				joga(tabJogo, corIA, linhaMuda, colMuda);
				printaTabuleiro(tabJogo);
			}else{
				printf("\tSem jogadas validas para a IA");
				semJogadaValida++;		
				if(semJogadaValida > 1){
					fimDeJogo = TRUE;
				}
			}

			quemJogaAgora = JOGADOR;
		}
		printf("\t_______________________________________\n\n\n");
		contadorRodadas += 1;

		pontosBranco = 0;
		pontosPreta = 0;

		for(int q = 0; q < 8; q++){
			for (int w = 0; w < 8; w++){
				//Contando os pontos
				if(tabJogo[q][w] != 0){
					if(tabJogo[q][w] == 1)
						pontosBranco += 1;
					else if(tabJogo[q][w] == -1)
						pontosPreta += 1;
				}
			}	
		}
	}

	if(pontosBranco > pontosPreta)
		printf("\n\tVitoria das pecas Pretas!");
	else if(pontosBranco < pontosPreta)
		printf("\n\tVitoria das pecas Brancas!");
	else
		printf("\n\tEmpate!");
	return 0;
}
