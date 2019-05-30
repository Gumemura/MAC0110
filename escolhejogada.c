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

#define CARDS 8
#define MAX 64


void escolhejogada(int tabuleiro[8][8], int cor, int *linha, int *coluna){
	int cpi = 0, api[MAX] = 0, al[MAX], cl[MAX], ca = 0;

	for(int linha = 0; linha < 8; linha++){
		for (int col = 0; col < 8; col++){
			if(tabuleiro[linha][col] == cor){
				for(int scan = 0; scan < CARDS; scan ++){

					if(scan == 0){ //Norte
						int linhaNO = linha + 1;

						while(tabuleiro[linhaNO][col] == cor *-1){
							cpi++;
							linhaNO--;
						}
					}

					if(api <= cpi){
						api[ca] = cpi;
						al[ca] = linhaNO;
						ac[ca] = col;
						ca++;
					}

					cpi = 0;


					/*if(scan == 1){
						if(){
							
						}
					}
					if(scan == 2){
						if(){
							
						}
					}
					if(scan == 3){
						if(){
							
						}
					}
					if(scan == 4){
						if(){
							
						}
					}
					if(scan == 5){
						if(){
							
						}
					}
					if(scan == 6){
						if(){
							
						}
					}
					if(scan == 7){
						if(){
							
						}
					}*/
				}
			}
		}
	}
}