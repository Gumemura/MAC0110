/*
Nome: Guilherme Umemura

nUSP: 9353592
*/

#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

char s1 = ' ',s2 = ' ',s3 = ' ',s4 = ' ',s5 = ' ',s6 = ' ',s7 = ' ',s8 = ' ',s9 = ' ';

int tabuleiroVelha();

int main(){

	int coluna, linha = 0;
	char inputSouO;

	printf("Digita as cordenadas do campo que quer alterar, e a letra que quer inserir\n");

	do{
		do{
			printf("Linha: ");
			scanf("%d", &linha);
			printf("\n");
			if(linha <= 0 || linha >= 4){ //problema na checagem de numero: se for digiatado qualquer coisa que nao um numero, loop infinito
				printf("Inserir valor entre 1 e 3 (existem apenas 3 linhas!)\n\n");
			}
		}while(linha <= 0 || linha >= 4);

		do{
			printf("Coluna: ");
			scanf("%d", &coluna);
			printf("\n");
			if(coluna <= 0 || coluna >= 4){ //problema na checagem de numero: se for digiatado qualquer coisa que nao um numero, loop infinito
				printf("Inserir valor entre 1 e 3 (existem apenas 3 colunas!)\n\n");
			}
		}while(coluna <= 0 || coluna >= 4);

		do{ //problema: ele executa um loop sem antes executar as etapas, mas o segundo loop é normal
			printf("Letra: ");
			scanf("%c ", &inputSouO);
			printf("\n");
			if(inputSouO != 's' && inputSouO != 'S' && inputSouO != 'o' && inputSouO != 'O'){
				printf("Inserir a letra S ou O (maiusculo ou minusculo)\n\n"); 
			}
		}while(inputSouO != 's' && inputSouO != 'S' && inputSouO != 'o' && inputSouO != 'O');

		if(linha == 1){
			if(coluna == 1)			{s1 = inputSouO;}
			else if(coluna == 2)	{s2 = inputSouO;}
			else if(coluna == 3)	{s3 = inputSouO;}
		}
		else if(linha == 2){
			if(coluna == 1)			{s4 = inputSouO;}
			else if(coluna == 2)	{s5 = inputSouO;}
			else if(coluna == 3)	{s6 = inputSouO;} 
		}
		else if(linha == 3){
			if(coluna == 1)			{s7 = inputSouO;}
			else if(coluna == 2)	{s8 = inputSouO;}
			else if(coluna == 3)	{s9 = inputSouO;}
		}

		tabuleiroVelha();

	}while(s1 != ' ' && s2 != ' ' && s3 != ' ' && s4 != ' ' && s5 != ' ' && s6 != ' ' && s7 != ' ' && s8 != ' ' && s9 != ' '); //problema: a condicao desse while n é verificada e o loop roda só uma vez
}

int tabuleiroVelha(){
	//Print da tabela
	int n1 = 0,n2 = 0,n3 = 0,n4 = 0,n5 = 0,n6 = 0,n7 = 0,n8 = 0,n9 = 0;
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




