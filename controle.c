/****************************************************************
    Nome: Guilherme Umemura
    NUSP: 9353592

    Fonte e comentários: 

****************************************************************/
#include <stdio.h>

#define FALSE 0;
#define TRUE 1;


int main(){
	int entraousai, nusp, horas, minutos, usuarios[15], flagAdcNusp = 1, contInsercoes = 0;
	char nomeDoc[20];
	
	FILE * doctxt;

	printf("Digite o nome do arquivo .txt a ser lido: ");
	scanf("%s", nomeDoc);

	doctxt = fopen(nomeDoc, "r");

	while(!feof(doctxt)){
		if(fscanf(doctxt, "%d %d %d:%d", &entraousai, &nusp, &horas, &minutos) != 4) continue;

		//Retorna a quantidade diferente de alunos que entraram na sala 
			for(int i = 0; i < 15; i++){
				if(nusp == usuarios[i])
					flagAdcNusp = FALSE;
			}
			if(flagAdcNusp){
				usuarios[contInsercoes] = nusp;
				contInsercoes++;
			}
			flagAdcNusp = TRUE;
	}

	printf("\nQuantidade diferentes de usuarios: %d", (contInsercoes));

	return 0;
}
