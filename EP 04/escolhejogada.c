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


int verificaVetor(int linhaCompara, int colCompara, int vectorCompara[3][MAX]){
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

void escolhejogada(int tabuleiro[8][8], int cor, int *linha, int *coluna){
	int linhaAnalise, colAnalise, cPI = 0, aPJ[3][MAX], cPJ = 0, pC = FALSE;
	//cPI = contador peças inimigas (conta quantas peças inimigas tem na sequencia analisada)
	//aPJ = armazem possiveis jogadas (em cada coluna há ters infos: a linha, coluna e quantidade de pontos q cada possivel jogada vai mudar)
	//cPJ = coluna possiveis jogadas (serve para indexar a coluna da matriz onde serao armazenadas as possiveis jogadas)
	//pC = pode contabilizar (serve para dizer que a sequencia de peças analisadas é um jogada valida, ou seja, a sequencia começa com uma peça da cor do computador, é seguida por peças inimigas, e termina com um campo vazio)

	for(int linha = 0; linha < 8; linha++){
		for (int col = 0; col < 8; col++){
			if(tabuleiro[linha][col] == cor){
				for(int sentidoNS = 0; sentidoNS < LIMITE; sentidoNS++){
					//Norte
					if(sentidoNS == 0){

						linhaAnalise = linha - 1;

						if(tabuleiro[linhaAnalise][col] == (cor * -1)){
							for(linhaAnalise = linha - 1; linhaAnalise >= 0; linhaAnalise--){
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
								linhaAnalise = linha - 1;

								if(linhaAnalise > 0){
									if(verificaVetor((linhaAnalise - 1), col, aPJ) == -1){
										aPJ[0][cPJ] = linhaAnalise;
										aPJ[1][cPJ] = col;
										aPJ[2][cPJ] = cPI;
										cPJ++;
									}else{
										aPJ[2][verificaVetor((linhaAnalise - 1), col, aPJ)] += cPI;
									}
								}
							}
						}

						printf("\n%d\n%d\n%d\n%d\n", aPJ[0][1], aPJ[1][1], aPJ[2][1], cPI);

						cPI = 0;
						pC = FALSE;
					}
				}
			}
		}
	}

	int maiorValor = 0;
	for(int sp = 0; sp < MAX; sp++){
		if(aPJ[3][sp] > maiorValor){
			*linha 			= aPJ[1][sp];
			*coluna 		= aPJ[2][sp];
			maiorValor 		= aPJ[3][sp];
		}
	}
}

void printaTabuleiro(int v[8][8]){
	printf("\n\t\t 0   1   2   3   4   5   6   7\n\n");
	printf("\t0\t %d ", v[0][0]); printf("|"); printf(" %d ", v[0][1]); printf("|"); printf(" %d ", v[0][2]); printf("|"); printf(" %d ", v[0][3]); printf("|"); printf(" %d ", v[0][4]); printf("|"); printf(" %d ", v[0][5]); printf("|"); printf(" %d ", v[0][6]); printf("|"); printf(" %d \n", v[0][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t1\t %d ", v[1][0]); printf("|"); printf(" %d ", v[1][1]); printf("|"); printf(" %d ", v[1][2]); printf("|"); printf(" %d ", v[1][3]); printf("|"); printf(" %d ", v[1][4]); printf("|"); printf(" %d ", v[1][5]); printf("|"); printf(" %d ", v[1][6]); printf("|"); printf(" %d \n", v[1][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t2\t %d ", v[2][0]); printf("|"); printf(" %d ", v[2][1]); printf("|"); printf(" %d ", v[2][2]); printf("|"); printf(" %d ", v[2][3]); printf("|"); printf(" %d ", v[2][4]); printf("|"); printf(" %d ", v[2][5]); printf("|"); printf(" %d ", v[2][6]); printf("|"); printf(" %d \n", v[2][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t3\t %d ", v[3][0]); printf("|"); printf(" %d ", v[3][1]); printf("|"); printf(" %d ", v[3][2]); printf("|"); printf(" %d ", v[3][3]); printf("|"); printf(" %d ", v[3][4]); printf("|"); printf(" %d ", v[3][5]); printf("|"); printf(" %d ", v[3][6]); printf("|"); printf(" %d \n", v[3][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t4\t %d ", v[4][0]); printf("|"); printf(" %d ", v[4][1]); printf("|"); printf(" %d ", v[4][2]); printf("|"); printf(" %d ", v[4][3]); printf("|"); printf(" %d ", v[4][4]); printf("|"); printf(" %d ", v[4][5]); printf("|"); printf(" %d ", v[4][6]); printf("|"); printf(" %d \n", v[4][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t5\t %d ", v[5][0]); printf("|"); printf(" %d ", v[5][1]); printf("|"); printf(" %d ", v[5][2]); printf("|"); printf(" %d ", v[5][3]); printf("|"); printf(" %d ", v[5][4]); printf("|"); printf(" %d ", v[5][5]); printf("|"); printf(" %d ", v[5][6]); printf("|"); printf(" %d \n", v[5][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t6\t %d ", v[6][0]); printf("|"); printf(" %d ", v[6][1]); printf("|"); printf(" %d ", v[6][2]); printf("|"); printf(" %d ", v[6][3]); printf("|"); printf(" %d ", v[6][4]); printf("|"); printf(" %d ", v[6][5]); printf("|"); printf(" %d ", v[6][6]); printf("|"); printf(" %d \n", v[6][7]);
	printf("\t\t---+---+---+---+---+---+---+---\n");
	printf("\t7\t %d ", v[7][0]); printf("|"); printf(" %d ", v[7][1]); printf("|"); printf(" %d ", v[7][2]); printf("|"); printf(" %d ", v[7][3]); printf("|"); printf(" %d ", v[7][4]); printf("|"); printf(" %d ", v[7][5]); printf("|"); printf(" %d ", v[7][6]); printf("|"); printf(" %d \n", v[7][7]);
}

int main(){
	int tabJogo[8][8], linhaMuda, colMuda;

	for(int q = 0; q < 8; q++){
		for (int w = 0; w < 8; w++){
			tabJogo[q][w] = 0;
		}
	}

	tabJogo[3][3] = 1;
	tabJogo[4][4] = 1;

	tabJogo[3][4] = -1;
	tabJogo[4][3] = -1;

	tabJogo[2][3] = 1;
	tabJogo[1][3] = 1;

	tabJogo[2][4] = 1;
	tabJogo[1][4] = 1;

	escolhejogada(tabJogo, -1, &linhaMuda, &colMuda);


	/*for(int e = 0; e < 8; e++){
		for (int r = 0; r < 8; r++){
			if(tabJogo[e][r] == -1)
				tabJogo[e][r] = 2;
		}
	}*/
	printf("\nDeveria vir 0 e 3\n\nLinha: %d\nColuna: %d\n\n", linhaMuda, colMuda);
	printaTabuleiro(tabJogo);

	return 0;
}