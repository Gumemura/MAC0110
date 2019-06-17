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


int campoRegistrado(int linhaCompara, int colCompara, int vectorCompara[3][MAX]){
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

void escolhejogada(int tabuleiroEJ[8][8], int corPC, int *linhaJogadaPC, int *colunaJogadaPC){
	int linhaAnalise, colAnalise, cPI = 0, aPJ[][], cPJ = 0, pC = FALSE;
	//cPI = contador peças inimigas (conta quantas peças inimigas tem na sequencia analisada)
	//aPJ = armazem possiveis jogadas (em cada coluna há ters infos: a linha, coluna e quantidade de pontos q cada possivel jogada vai mudar)
	//cPJ = coluna possiveis jogadas (serve para indexar a coluna da matriz onde serao armazenadas as possiveis jogadas)
	//pC = pode contabilizar (serve para dizer que a sequencia de peças analisadas é um jogada valida, ou seja, a sequencia começa com uma peça da cor do computador, é seguida por peças inimigas, e termina com um campo vazio)

	for(int linha = 0; linha < 8; linha++){
		for (int col = 0; col < 8; col++){
			if(tabuleiroEJ[linha][col] == corPC){
				for(int sentidoNS = 0; sentidoNS < LIMITE; sentidoNS++){
					//Norte
					if(sentidoNS == 0){
						linhaAnalise = linha - 1;

						if(tabuleiroEJ[linhaAnalise][col] == (corPC * -1)){
							for(linhaAnalise > 0){
								if(tabuleiroEJ[linhaAnalise][col] == (corPC * -1)){
									cPI++;
								}else if(tabuleiroEJ[linhaAnalise][col] == 0){
									pC = TRUE;
									break;
								}else{
									break;
								}
								linhaAnalise--;
							}

							linhaAnalise = linha - 1;

							if(linhaAnalise > 0){
								if(campoRegistrado((linhaAnalise - 1), col, aPJ[3][MAX]) == -1){
									campoRegistrado[0][cPJ] = linhaAnalise;
									campoRegistrado[1][cPJ] = col;
									campoRegistrado[2][cPJ] = cPI;
									cPJ++;
								}else{
									campoRegistrado[2][campoRegistrado((linhaAnalise - 1), col, aPJ[3][MAX])] += cPJ;
								}
							}
						}
					}
				}
			}
		}
	}
}

void printaTabuleiro{
	printf("\t\t0"); printf("|"); printf("0"); printf("|"); printf("0\n");
	printf("\t\t-+-+-\n");
	printf("\t\t0"); printf("|"); printf("0"); printf("|"); printf("0\n");
	printf("\t\t-+-+-\n");
	printf("\t\t0"); printf("|"); printf("0"); printf("|"); printf("0\n");
}

int main(){
	//int tabuleiro[8][8];

	printaTabuleiro;


}