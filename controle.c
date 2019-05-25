/****************************************************************
    Nome: Guilherme Umemura
    NUSP: 9353592

    Fonte e comentários: Dados a serem coletados: (i)numero total de usuarios diferentes do salao; e (ii) lista ordenada pelo NUSP dos usuarios do salao, com informacao de quanto tempo ficaram em cada visita;

****************************************************************/
#include <stdio.h>

#define FALSE 0
#define TRUE 1


int main(){
	int entraousai, nusp, horas, minutos, usuarios[50], flagAdcNusp = TRUE, contInsercoes = FALSE, horaEntra[50], minutoEntra[50], horaSai[50], minutoSai[50];
	int contEntra = -1, quemEntra[50], temSaida[50], temEntrada[50];
	char nomeDoc[20];

	
	FILE * doctxt;

	printf("Digite o nome do arquivo .txt a ser lido: ");
	scanf("%s", nomeDoc);

	doctxt = fopen(nomeDoc, "r");

	while(!feof(doctxt)){
		if(fscanf(doctxt, "%d %d %d:%d", &entraousai, &nusp, &horas, &minutos) != 4) continue;

		//Retorna o numero total de usuarios diferentes na sala
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
			horaEntra[contEntra] = horas;
			minutoEntra[contEntra] = minutos;
			quemEntra[contEntra] = nusp;
			temEntrada[contEntra] = TRUE;
		}else{
			int achouCorresp = FALSE;
			for(int x = 0; x < contEntra + 1; x++){
				//Esse 'for' relaciona o horario de saida a pessoa que previamente entrou
				if(nusp == quemEntra[x]){
					horaSai[x] = horas;
					minutoSai[x] = minutos;
					temSaida[x] = TRUE;
					achouCorresp = TRUE;
				}
			}
			if(achouCorresp == FALSE){
				contEntra++;
				quemEntra[contEntra] = nusp;
				horaSai[contEntra] = horas;
				minutoSai[contEntra] = minutos;
				temSaida[contEntra] = TRUE;
				temEntrada[contEntra] = FALSE;
			}
			achouCorresp = FALSE;
		}
	}

	for(int z = 0; z < contEntra + 1; z++){
		printf("%d\t", quemEntra[z]);

		int contAlgarismos = 0;
		while(quemEntra[z] != 0){
			contAlgarismos++;
			quemEntra[z] /= 10;
		}
		if(contAlgarismos <= 7)
			printf("\t");

		if(temEntrada[z])
			printf("%d:%d", horaEntra[z], minutoEntra[z]);


		if(temSaida[z] == TRUE)
			printf("\t%d:%d", horaSai[z], minutoSai[z]);
		printf("\n");
	}
	
	printf("\nQuantidade diferentes de usuarios: %d", (contInsercoes));

	return 0;
}
