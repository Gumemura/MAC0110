#include <stdio.h>

int main()
{
    int jogador1, jogador2, jogador1ok = 0, jogador2ok = 0;
    int jogarDeNovo = 0;

    do{
        printf("1 - Pedra | 2 - Papel | 3 - Tesoura\n");

        //Input do 1o jogador
        do{
            printf("Insira jogada do primeiro jogador: ");
            scanf("%d", &jogador1);

            if(jogador1 > 3 || jogador1 < 1){
                printf("\nNúmero inválido!\n");
            }else{
                jogador1ok = 1;
            }
        }while(jogador1ok == 0);

        //Input do 2o jogador
        do{
            printf("\nInsira jogada do segundo jogador: ");
            scanf("%d", &jogador2);

            if(jogador2 > 3 || jogador2 < 1){
                printf("Número inválido!\n");
            }else{
                jogador2ok = 1;
            }
        }while(jogador2ok == 0);

        //Comparação dos resultados
        if(jogador1 == jogador2){
            printf("\nRESULTADO: Empate!");
        }else{
            printf("\nRESULTADO: ");
            if(jogador1 == 1){
                if(jogador2 == 2){
                    printf("O segundo jogador ganhou!");
                }else{
                    printf("O primeiro jogador ganhou!");
                }
            }
            if(jogador1 == 2){
                if(jogador2 == 1){
                    printf("O primeiro jogador ganhou!");
                }else{
                    printf("O segundo jogador ganhou!");
                }
            }
            if(jogador1 == 3){
                if(jogador2 == 1){
                    printf("O segundo jogador ganhou!");
                }else{
                    printf("O primeiro jogador ganhou!");
                }
            }
        }
        printf("\n\nDeseja jogar novamente? 0 - Sim! | 1 - Não :(");
        scanf("%d", &jogarDeNovo);
        if(jogarDeNovo == 1){
            printf("\nVlw por jogar :D !!\n\n\n\n");
        }else{
            printf("\n\n############ NOVO JOGO ############\n\n");
        }
        jogador1ok = 0;
        jogador2ok = 0;
    }while(jogarDeNovo == 0);

    return 0;
}
