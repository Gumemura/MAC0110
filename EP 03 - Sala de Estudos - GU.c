/****************************************************************
    Nome: Guilherme Umemura
    NUSP: 9353592

    Fonte e comentários: Dados a serem coletados: 
    	(i)numero total de usuarios diferentes do salao; e 
    	(ii) lista ordenada pelo NUSP dos usuarios do salao, com informacao de quanto tempo ficaram em cada visita;

****************************************************************/
#include <stdio.h>

#define FALSE 0
#define TRUE 1


int main(){
	char nomeDoc[20];
	int entraousai, nusp, horas, minutos, usuarios[50], flagAdcNusp = TRUE, contInsercoes = 0;

	int contEntra = -1;
	int quemEntra[50];
	int horaEntra[50], minutoEntra[50];
	int horaSai[50], minutoSai[50];
	int flagTemSaida[50], flagTemEntrada[50], flagAchouSaida[50];
	int tempoPermanencia[50];

	FILE * doctxt;

	printf("\nDigite o nome do arquivo .txt a ser lido: ");
	scanf("%s", nomeDoc);
	printf("\n");

	doctxt = fopen(nomeDoc, "r");

	while(!feof(doctxt)){
		if(fscanf(doctxt, "%d %d %d:%d", &entraousai, &nusp, &horas, &minutos) != 4) continue;

		//Retorna o numero total de usuarios distintos que estiveram na sala
		for(int i = 0; i < 50; i++){
			if(nusp == usuarios[i])
				flagAdcNusp = FALSE;
		}
		if(flagAdcNusp){
			usuarios[contInsercoes] = nusp;
			contInsercoes++;
		}
		flagAdcNusp = TRUE;


		//Retorna quanto tempo cada aluno ficou na sala
		if(entraousai == 0){
			contEntra++;
			quemEntra[contEntra] = nusp;
			horaEntra[contEntra] = horas;
			minutoEntra[contEntra] = minutos;
			flagTemEntrada[contEntra] = TRUE;
			flagTemSaida[contEntra] = FALSE;
			flagAchouSaida[contEntra] = FALSE;
		}else{
			int achouCorresp = FALSE;
			for(int x = 0; x < contEntra + 1; x++){
				//Esse 'for' relaciona o horario de saida a pessoa que previamente entrou
				if(nusp == quemEntra[x] && flagAchouSaida[x] == FALSE){
					horaSai[x] = horas;
					minutoSai[x] = minutos;
					flagTemSaida[x] = TRUE;
					achouCorresp = TRUE;
					flagAchouSaida[x] = TRUE;
				}
			}
			if(achouCorresp == FALSE){
				//Esse 'if' pega o horario de saida daqueles que nao entraram
				contEntra++;
				quemEntra[contEntra] = nusp;
				horaSai[contEntra] = horas;
				minutoSai[contEntra] = minutos;
				flagTemSaida[contEntra] = TRUE;
				flagTemEntrada[contEntra] = FALSE;
			}
			achouCorresp = FALSE;
		}
	}

	printf("\nQuantidade alunos distintos que estiveram na sala de estudos: %d\n\n", (contInsercoes));

	printf("NUSP\t\tENTRADA\t\tSAIDA\tPERMANENCIA\n");

	for(int z = 0; z < contEntra + 1; z++){
		int contAlgarismos = 0;

		if(flagTemEntrada[z] == TRUE && flagTemSaida[z] == TRUE)
			tempoPermanencia[z] = ((horaSai[z] * 60 ) + minutoSai[z]) - ((horaEntra[z] * 60) + minutoEntra[z]);

		if(flagTemEntrada[z] == TRUE && flagTemSaida[z] == FALSE)
			tempoPermanencia[z] = (24*60 - ((horaEntra[z] * 60) + minutoEntra[z]));

		if(flagTemEntrada[z] == FALSE && flagTemSaida[z] == TRUE)
			tempoPermanencia[z] = (horaSai[z] * 60) + minutoSai[z];

		printf("%d\t", quemEntra[z]);

		while(quemEntra[z] != 0){
			contAlgarismos++;
			quemEntra[z] /= 10;
		}
		if(contAlgarismos <= 7)
			printf("\t");

		if(flagTemEntrada[z] == TRUE){
			printf("%d:%d", horaEntra[z], minutoEntra[z]);
			if(flagTemSaida[z] == FALSE)
				printf("\t\t");
		}

		if(flagTemSaida[z] == TRUE)
			printf("\t\t%d:%d", horaSai[z], minutoSai[z]);

		printf("\t%d\n", tempoPermanencia[z]);
	}

	return 0;
}