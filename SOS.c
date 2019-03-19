    #include <stdio.h>
#define human_turn 1            /*indicador de turno do jogador humano*/
#define robot_turn 2            /*indicador de turno do computador*/
#define sem_erro 3              /*indicador de jogada humana valida*/
#define com_erro 4              /*indicador de jogada invalida*/

int main ()
{

    int A,B,C,D,E,F,G,H,I,      /*variaveis que guardam a letra em cada casa*/
    letra,linha,coluna,         /*3 dados que o jogador humano indica para uma jogada*/
    casa,                       /*variavel que indica a posicao de 0 a 8, conforme a linha e coluna indicado pelo jogador*/
    round,                      /*contagem de jogadas*/
    total,                      /*calculo da codificacao do tabuleiro da jogada*/
    resto,                      /*valor que indicara qual a informacao que cada posicao do tabuleiro possui*/
    cont,base,                  /*variaveis para o calculo de base 3 elevado a potencia de "casa" (posicao do tabuleiro)*/
    sos,ptos_human,ptos_robot,  /*quantidade de sos formados, pontos efetuados pelo jogador e computador, respectivamente*/
    points,                     /*contagem de sos(s) formado(s) em uma jogada, tanto do jogador, quanto do computador*/
    turn,                       /*indicador de turno*/
    erro;                       /*a variavel indica se a jogada foi valida ou nao, ou seja, se foi escolhida uma posicao vazia*/

    /*valores iniciais para variaveis*/
    /*as seguintes variaveis fazem parte de expressoes matematicas, portanto necessitam de um valor inicial, neste caso: zero*/
    total=round=linha=linha=coluna=casa=cont=resto=sos=ptos_human=ptos_robot=points=0;
    /*As casas devem ter valor zero sendo que estao inicialmente vazias*/
    A=B=C=D=E=F=G=H=I=0;
    /*o jogo inicia sem que nao houve jogada invalida*/
    erro=sem_erro;

    /*Introducao do jogo e solicitacao de entrada do jogador*/
    printf (":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n::::::+==============+::::::+==============+::::::+==============+:::::::\n:::::{{--------------}}::::{{--------------}}::::{{--------------}}::::::\n:::::{{------+=======+:::::{{----+====+----}}::::{{------+=======+:::::::\n:::::{{------}}::::::::::::{{---{{::::}}---}}::::{{------}}::::::::::::::\n:::::{{------+=======+:::::{{---{{::::}}---}}::::{{------+=======+:::::::\n:::::{{--------------}}::::{{---{{::::}}---}}::::{{--------------}}::::::\n::::::+=======+------}}::::{{---{{::::}}---}}:::::+=======+------}}::::::\n:::::::::::::{{------}}::::{{---{{::::}}---}}::::::::::::{{------}}::::::\n::::::+=======+------}}::::{{----+====+----}}:::::+=======+------}}::::::\n:::::{{--------------}}::::{{--------------}}::::{{--------------}}::::::\n::::::+==============+::::::+==============+::::::+==============+:::::::\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n:::::::::GAME:::GAME:::GAME:::GAME:::GAME:::GAME:::GAME:::GAME:::::::::::\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf ("\n - SOS GAME - \n\nBem-vindo!\nSe deseja comecar, digite 1.\nOu 2, para computador comecar.\n\nSeu digito: ");
    scanf ("%d",&turn);

    /*Breve visualizacao do tabuleiro e placar do jogo*/
    printf("\nInicio:\n\n     |     |      \n-----+-----+-----\n     |     |      \n-----+-----+-----\n     |     |      \n\n");
    printf ("Ha %d SOS(s) formado(s)\nPontos: HUMANO %d X %d COMPUTADOR\n",sos,ptos_human,ptos_robot);

    /*inicio do "looping". Considerando que 9 casas deverao ser preenchidas, serao permitidas 9 jogadas*/
    while (round<9) {
        if (turn==human_turn && erro==sem_erro) {     /*turno do jogador e inicio de uma jogada valida*/
            printf ("\nPartida do jogador...");
            printf ("\nIndique 1 para S e 2 para O: ");
            scanf ("%d",&letra);
            printf ("Indique a linha: ");
            scanf ("%d",&linha);
            printf ("Indique a coluna: ");
            scanf ("%d",&coluna);

            /*a expressao a seguir calcula o valor da posicao dado a linha e a coluna*/
            casa=3*(linha-1)+(coluna-1);

            /*A seguir, inicia a verificacao se a jogada humana foi valida: se o jogador escolheu uma posicao vazia, ou seja, sem nenhuma letra*/
            if (casa==0&&A!=0||casa==1&&B!=0||casa==2&&C!=0||casa==3&&D!=0||casa==4&&E!=0||casa==5&&F!=0||casa==6&&G!=0||casa==7&&H!=0||casa==8&&I!=0)  {
                printf ("\n:::::::::Jogada invalida!:::::::::\nJogue novamente...\n");

                /*"erro" recebe o valor que indica que houve uma jogada invalida*/
                erro=com_erro;
            }

            /*se a jogada for valida, o programa ira ler os proximos passos, caso contrario, havera um pulo para uma condicao valida*/
            if (erro==sem_erro) {

                /*a seguir, calcula-se uma operacao exponencial de base 3
                com expoente "valor da posicao do tabuleiro", necessarios para verificar
                cada informacao que esta contido nas posicoes do tabuleiro*/
                base=1;     /*posicao 0, 3 elevado a 0 vale 1*/
                for (cont=0;cont<casa;cont++) base=base*3;

                /*cada "casa" tera uma variavel de A a I,
                em que cada letra ira receber o valor da letra indicada pelo jogador*/
                if (casa==0)    A=letra;
                if (casa==1)    B=letra;
                if (casa==2)    C=letra;
                if (casa==3)    D=letra;
                if (casa==4)    E=letra;
                if (casa==5)    F=letra;
                if (casa==6)    G=letra;
                if (casa==7)    H=letra;
                if (casa==8)    I=letra;

                /*Operacao para codificacao do tabuleiro e "resto" que indicara
                a informacao contida no "total"*/
                total=A*1+B*3+C*9+D*27+E*81+F*243+G*729+H*2187+I*6561;
                resto=total/base%3;

                /*impressao do tabuleiro*/
                /*para cada letra que contem uma informacao, seja vazia, S ou O, deve
                ser impresso a situacao presente*/
                if (letra==resto)    {
                    if (A==0)   printf("     |");
                    if (A==1)   printf("  S  |");
                    if (A==2)   printf("  O  |");
                    if (B==0)   printf("     |");
                    if (B==1)   printf("  S  |");
                    if (B==2)   printf("  O  |");
                    if (C==0)   printf("     \n-----+-----+-----\n");
                    if (C==1)   printf("  S  \n-----+-----+-----\n");
                    if (C==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 1*/
                    if (D==0)   printf("     |");
                    if (D==1)   printf("  S  |");
                    if (D==2)   printf("  O  |");
                    if (E==0)   printf("     |");
                    if (E==1)   printf("  S  |");
                    if (E==2)   printf("  O  |");
                    if (F==0)   printf("     \n-----+-----+-----\n");
                    if (F==1)   printf("  S  \n-----+-----+-----\n");
                    if (F==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 2*/
                    if (G==0)   printf("     |");
                    if (G==1)   printf("  S  |");
                    if (G==2)   printf("  O  |");
                    if (H==0)   printf("     |");
                    if (H==1)   printf("  S  |");
                    if (H==2)   printf("  O  |");
                    if (I==0)   printf("     \n");
                    if (I==1)   printf("  S  \n");
                    if (I==2)   printf("  O  \n");                          /*fim da linha 3*/
                    }
                /*termino da jogada humana, portanto, adiciona-se uma partida ("round") realizada*/
                round++;
                /*"turn" recebe informacao de que proxima jogada deve ser do computador*/
                turn=robot_turn;

                /*Inicia-se a seguir se cada jogada realizada pelo jogador
                formou um SOS valido. Para cada casa, ha um certo numero de SOSs validos.
                Por exemplo, na primeira casa, poderao formar 3 SOSs: uma horizontal, uma vertical e uma diagonal*/
                /*cada SOS formado, serao adicionados pontos ("points")*/
                if (casa==0)    {
                    if (A==1 && B==2 && C==1)   points++;
                    if (A==1 && E==2 && I==1)   points++;
                    if (A==1 && D==2 && G==1)   points++;
                }
                if (casa==1)    {
                    if (A==1 && B==2 && C==1)   points++;
                    if (B==1 && E==2 && H==1)   points++;
                }
                if (casa==2)    {
                    if (A==1 && B==2 && C==1)   points++;
                    if (C==1 && E==2 && G==1)   points++;
                    if (C==1 && F==2 && I==1)   points++;
                }
                if (casa==3)    {
                    if (D==1 && E==2 && F==1)   points++;
                    if (A==1 && D==2 && G==1)   points++;
                }
                if (casa==4)    {
                    if (D==1 && E==2 && F==1)   points++;
                    if (A==1 && E==2 && I==1)   points++;
                    if (B==1 && E==2 && H==1)   points++;
                    if (C==1 && E==2 && G==1)   points++;
                }
                if (casa==5)    {
                    if (D==1 && E==2 && F==1)   points++;
                    if (C==1 && F==2 && I==1)   points++;
                }
                if (casa==6)    {
                    if (G==1 && H==2 && I==1)   points++;
                    if (C==1 && E==2 && G==1)   points++;
                    if (A==1 && D==2 && G==1)   points++;
                }
                if (casa==7)    {
                    if (G==1 && H==2 && I==1)   points++;
                    if (B==1 && E==2 && H==1)   points++;
                }
                if (casa==8)    {
                    if (G==1 && H==2 && I==1)   points++;
                    if (A==1 && E==2 && I==1)   points++;
                    if (C==1 && F==2 && I==1)   points++;
                }
                /*os "points" serao adicionados ao ponto do jogador atual ("ptos_human")*/
                ptos_human+=points;

                /*caso foi realizado ao menos um ponto, o jogador atual recebe mais uma partida,
                neste caso, "turn" indicara ao programa pular para o inicio, novamente*/
                if (points>0)   turn=human_turn;

                 /*"points" volta a zerar, para nao entrar em conflito com a jogada do computador*/
                points=0;

                /*pontos efetuados pelo humano e pelo computador serao guardados e somados na variavel "sos"*/
                sos=ptos_robot+ptos_human;
                printf ("Ha %d SOS(s) formado(s)\nPontos: HUMANO %d X %d COMPUTADOR\n",sos,ptos_human,ptos_robot);
            }
        }

            if (turn==robot_turn && erro==sem_erro)   {       /*turno do computador e inicio de uma jogada valida*/

                /*A SEGUIR, INICIA A PROGRAMACAO EM QUE O COMPUTADOR PRENCHERA UMA DETERMINADA LETRA EM CADA CASA, CONSECUTIVAMENTE DE 0 A 8*/
                if (A==0) {                 /*Se a posicao 0 estiver vazia, o computador ira prencher com uma letra*/

                    /*computador tera jogadas ja programadas, portanto, letras e posicoes terao valores pre-estabelecidos*/
                    printf ("\nPartida do computador...\n");
                    letra=1;casa=0;

                    /*a seguir, calcula-se uma operacao exponencial de base 3
                    com expoente "valor da posicao do tabuleiro", necessarios para verificar
                    cada informacao que esta contido nas posicoes do tabuleiro*/
                    base=1;
                    for (cont=0;cont<casa;cont++) base=base*3;

                    /*cada "casa" tera uma variavel de A a I,
                    em que cada letra ira receber o valor da letra indicada pelo jogador*/
                    if (casa==0)    A=letra;
                    if (casa==1)    B=letra;
                    if (casa==2)    C=letra;
                    if (casa==3)    D=letra;
                    if (casa==4)    E=letra;
                    if (casa==5)    F=letra;
                    if (casa==6)    G=letra;
                    if (casa==7)    H=letra;
                    if (casa==8)    I=letra;

                    /*Operacao para codificacao do tabuleiro e "resto" que indicara
                    a informacao contida no "total"*/
                    total=A*1+B*3+C*9+D*27+E*81+F*243+G*729+H*2187+I*6561;
                    resto=total/base%3;

                    /*impressao do tabuleiro*/
                    /*para cada letra que contem uma informacao, seja vazia, S ou O, deve
                    ser impresso a situacao presente*/
                    if (letra==resto)    {
                        if (A==0)   printf("     |");
                        if (A==1)   printf("  S  |");
                        if (A==2)   printf("  O  |");
                        if (B==0)   printf("     |");
                        if (B==1)   printf("  S  |");
                        if (B==2)   printf("  O  |");
                        if (C==0)   printf("     \n-----+-----+-----\n");
                        if (C==1)   printf("  S  \n-----+-----+-----\n");
                        if (C==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 1*/
                        if (D==0)   printf("     |");
                        if (D==1)   printf("  S  |");
                        if (D==2)   printf("  O  |");
                        if (E==0)   printf("     |");
                        if (E==1)   printf("  S  |");
                        if (E==2)   printf("  O  |");
                        if (F==0)   printf("     \n-----+-----+-----\n");
                        if (F==1)   printf("  S  \n-----+-----+-----\n");
                        if (F==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 2*/
                        if (G==0)   printf("     |");
                        if (G==1)   printf("  S  |");
                        if (G==2)   printf("  O  |");
                        if (H==0)   printf("     |");
                        if (H==1)   printf("  S  |");
                        if (H==2)   printf("  O  |");
                        if (I==0)   printf("     \n");
                        if (I==1)   printf("  S  \n");
                        if (I==2)   printf("  O  \n");
                    }
                    /*termino da jogada do computador, portanto, adiciona-se uma partida ("round") realizada*/
                    round++;
                    /*"turn" recebe informacao de que proxima jogada deve ser humana*/
                    turn=human_turn;
                }

                if (turn==robot_turn && A!=0 && B==0) {

                    printf ("\nPartida do computador...\n");
                    letra=1;casa=1;

                    /*a seguir, calcula-se uma operacao exponencial de base 3
                    com expoente "valor da posicao do tabuleiro", necessarios para verificar
                    cada informacao que esta contido nas posicoes do tabuleiro*/
                    base=1;
                    for (cont=0;cont<casa;cont++) base=base*3;

                    /*cada "casa" tera uma variavel de A a I,
                    em que cada letra ira receber o valor da letra indicada pelo jogador*/
                    if (casa==0)    A=letra;
                    if (casa==1)    B=letra;
                    if (casa==2)    C=letra;
                    if (casa==3)    D=letra;
                    if (casa==4)    E=letra;
                    if (casa==5)    F=letra;
                    if (casa==6)    G=letra;
                    if (casa==7)    H=letra;
                    if (casa==8)    I=letra;

                    /*Operacao para codificacao do tabuleiro e "resto" que indicara
                    a informacao contida no "total"*/
                    total=A*1+B*3+C*9+D*27+E*81+F*243+G*729+H*2187+I*6561;
                    resto=total/base%3;

                    /*impressao do tabuleiro*/
                    /*para cada letra que contem uma informacao, seja vazia, S ou O, deve
                    ser impresso a situacao presente*/
                    if (letra==resto)    {
                        if (A==0)   printf("     |");
                        if (A==1)   printf("  S  |");
                        if (A==2)   printf("  O  |");
                        if (B==0)   printf("     |");
                        if (B==1)   printf("  S  |");
                        if (B==2)   printf("  O  |");
                        if (C==0)   printf("     \n-----+-----+-----\n");
                        if (C==1)   printf("  S  \n-----+-----+-----\n");
                        if (C==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 1*/
                        if (D==0)   printf("     |");
                        if (D==1)   printf("  S  |");
                        if (D==2)   printf("  O  |");
                        if (E==0)   printf("     |");
                        if (E==1)   printf("  S  |");
                        if (E==2)   printf("  O  |");
                        if (F==0)   printf("     \n-----+-----+-----\n");
                        if (F==1)   printf("  S  \n-----+-----+-----\n");
                        if (F==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 2*/
                        if (G==0)   printf("     |");
                        if (G==1)   printf("  S  |");
                        if (G==2)   printf("  O  |");
                        if (H==0)   printf("     |");
                        if (H==1)   printf("  S  |");
                        if (H==2)   printf("  O  |");
                        if (I==0)   printf("     \n");
                        if (I==1)   printf("  S  \n");
                        if (I==2)   printf("  O  \n");
                    }
                    /*termino da jogada do computador, portanto, adiciona-se uma partida ("round") realizada*/
                    round++;
                    /*"turn" recebe informacao de que proxima jogada deve ser humana*/
                    turn=human_turn;
                }

                if (turn==robot_turn && A!=0 && B!=0 && C==0) {

                    printf ("\nPartida do computador...\n");
                    letra=1;casa=2;

                    /*a seguir, calcula-se uma operacao exponencial de base 3
                    com expoente "valor da posicao do tabuleiro", necessarios para verificar
                    cada informacao que esta contido nas posicoes do tabuleiro*/
                    base=1;
                    for (cont=0;cont<casa;cont++) base=base*3;

                    /*cada "casa" tera uma variavel de A a I,
                    em que cada letra ira receber o valor da letra indicada pelo jogador*/
                    if (casa==0)    A=letra;
                    if (casa==1)    B=letra;
                    if (casa==2)    C=letra;
                    if (casa==3)    D=letra;
                    if (casa==4)    E=letra;
                    if (casa==5)    F=letra;
                    if (casa==6)    G=letra;
                    if (casa==7)    H=letra;
                    if (casa==8)    I=letra;

                    /*Operacao para codificacao do tabuleiro e "resto" que indicara
                    a informacao contida no "total"*/
                    total=A*1+B*3+C*9+D*27+E*81+F*243+G*729+H*2187+I*6561;
                    resto=total/base%3;

                    /*impressao do tabuleiro*/
                    /*para cada letra que contem uma informacao, seja vazia, S ou O, deve
                    ser impresso a situacao presente*/
                    if (letra==resto)    {
                        if (A==0)   printf("     |");
                        if (A==1)   printf("  S  |");
                        if (A==2)   printf("  O  |");
                        if (B==0)   printf("     |");
                        if (B==1)   printf("  S  |");
                        if (B==2)   printf("  O  |");
                        if (C==0)   printf("     \n-----+-----+-----\n");
                        if (C==1)   printf("  S  \n-----+-----+-----\n");
                        if (C==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 1*/
                        if (D==0)   printf("     |");
                        if (D==1)   printf("  S  |");
                        if (D==2)   printf("  O  |");
                        if (E==0)   printf("     |");
                        if (E==1)   printf("  S  |");
                        if (E==2)   printf("  O  |");
                        if (F==0)   printf("     \n-----+-----+-----\n");
                        if (F==1)   printf("  S  \n-----+-----+-----\n");
                        if (F==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 2*/
                        if (G==0)   printf("     |");
                        if (G==1)   printf("  S  |");
                        if (G==2)   printf("  O  |");
                        if (H==0)   printf("     |");
                        if (H==1)   printf("  S  |");
                        if (H==2)   printf("  O  |");
                        if (I==0)   printf("     \n");
                        if (I==1)   printf("  S  \n");
                        if (I==2)   printf("  O  \n");
                    }
                    /*termino da jogada do computador, portanto, adiciona-se uma partida ("round") realizada*/
                    round++;
                    /*"turn" recebe informacao de que proxima jogada deve ser humana*/
                    turn=human_turn;
                }

                if (turn==robot_turn && A!=0 && B!=0 && C!=0 && D==0) {

                    printf ("\nPartida do computador...\n");
                    letra=2;casa=3;

                    /*a seguir, calcula-se uma operacao exponencial de base 3
                    com expoente "valor da posicao do tabuleiro", necessarios para verificar
                    cada informacao que esta contido nas posicoes do tabuleiro*/
                    base=1;
                    for (cont=0;cont<casa;cont++) base=base*3;

                    /*cada "casa" tera uma variavel de A a I,
                    em que cada letra ira receber o valor da letra indicada pelo jogador*/
                    if (casa==0)    A=letra;
                    if (casa==1)    B=letra;
                    if (casa==2)    C=letra;
                    if (casa==3)    D=letra;
                    if (casa==4)    E=letra;
                    if (casa==5)    F=letra;
                    if (casa==6)    G=letra;
                    if (casa==7)    H=letra;
                    if (casa==8)    I=letra;

                    /*Operacao para codificacao do tabuleiro e "resto" que indicara
                    a informacao contida no "total"*/
                    total=A*1+B*3+C*9+D*27+E*81+F*243+G*729+H*2187+I*6561;
                    resto=total/base%3;

                    /*impressao do tabuleiro*/
                    /*para cada letra que contem uma informacao, seja vazia, S ou O, deve
                    ser impresso a situacao presente*/
                    if (letra==resto)    {
                        if (A==0)   printf("     |");
                        if (A==1)   printf("  S  |");
                        if (A==2)   printf("  O  |");
                        if (B==0)   printf("     |");
                        if (B==1)   printf("  S  |");
                        if (B==2)   printf("  O  |");
                        if (C==0)   printf("     \n-----+-----+-----\n");
                        if (C==1)   printf("  S  \n-----+-----+-----\n");
                        if (C==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 1*/
                        if (D==0)   printf("     |");
                        if (D==1)   printf("  S  |");
                        if (D==2)   printf("  O  |");
                        if (E==0)   printf("     |");
                        if (E==1)   printf("  S  |");
                        if (E==2)   printf("  O  |");
                        if (F==0)   printf("     \n-----+-----+-----\n");
                        if (F==1)   printf("  S  \n-----+-----+-----\n");
                        if (F==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 2*/
                        if (G==0)   printf("     |");
                        if (G==1)   printf("  S  |");
                        if (G==2)   printf("  O  |");
                        if (H==0)   printf("     |");
                        if (H==1)   printf("  S  |");
                        if (H==2)   printf("  O  |");
                        if (I==0)   printf("     \n");
                        if (I==1)   printf("  S  \n");
                        if (I==2)   printf("  O  \n");
                    }
                    /*termino da jogada do computador, portanto, adiciona-se uma partida ("round") realizada*/
                    round++;
                    /*"turn" recebe informacao de que proxima jogada deve ser humana*/
                    turn=human_turn;
                }

                if (turn==robot_turn && A!=0 && B!=0 && C!=0 && D!=0 && E==0) {

                    printf ("\nPartida do computador...\n");
                    letra=2;casa=4;

                    /*a seguir, calcula-se uma operacao exponencial de base 3
                    com expoente "valor da posicao do tabuleiro", necessarios para verificar
                    cada informacao que esta contido nas posicoes do tabuleiro*/
                    base=1;
                    for (cont=0;cont<casa;cont++) base=base*3;

                    /*cada "casa" tera uma variavel de A a I,
                    em que cada letra ira receber o valor da letra indicada pelo jogador*/
                    if (casa==0)    A=letra;
                    if (casa==1)    B=letra;
                    if (casa==2)    C=letra;
                    if (casa==3)    D=letra;
                    if (casa==4)    E=letra;
                    if (casa==5)    F=letra;
                    if (casa==6)    G=letra;
                    if (casa==7)    H=letra;
                    if (casa==8)    I=letra;

                    /*Operacao para codificacao do tabuleiro e "resto" que indicara
                    a informacao contida no "total"*/
                    total=A*1+B*3+C*9+D*27+E*81+F*243+G*729+H*2187+I*6561;
                    resto=total/base%3;

                    /*impressao do tabuleiro*/
                    /*para cada letra que contem uma informacao, seja vazia, S ou O, deve
                    ser impresso a situacao presente*/
                    if (letra==resto)    {
                        if (A==0)   printf("     |");
                        if (A==1)   printf("  S  |");
                        if (A==2)   printf("  O  |");
                        if (B==0)   printf("     |");
                        if (B==1)   printf("  S  |");
                        if (B==2)   printf("  O  |");
                        if (C==0)   printf("     \n-----+-----+-----\n");
                        if (C==1)   printf("  S  \n-----+-----+-----\n");
                        if (C==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 1*/
                        if (D==0)   printf("     |");
                        if (D==1)   printf("  S  |");
                        if (D==2)   printf("  O  |");
                        if (E==0)   printf("     |");
                        if (E==1)   printf("  S  |");
                        if (E==2)   printf("  O  |");
                        if (F==0)   printf("     \n-----+-----+-----\n");
                        if (F==1)   printf("  S  \n-----+-----+-----\n");
                        if (F==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 2*/
                        if (G==0)   printf("     |");
                        if (G==1)   printf("  S  |");
                        if (G==2)   printf("  O  |");
                        if (H==0)   printf("     |");
                        if (H==1)   printf("  S  |");
                        if (H==2)   printf("  O  |");
                        if (I==0)   printf("     \n");
                        if (I==1)   printf("  S  \n");
                        if (I==2)   printf("  O  \n");
                    }
                    /*termino da jogada do computador, portanto, adiciona-se uma partida ("round") realizada*/
                    round++;
                    /*"turn" recebe informacao de que proxima jogada deve ser humana*/
                    turn=human_turn;
                }

                if (turn==robot_turn && A!=0 && B!=0 && C!=0 && D!=0 && E!=0 && F==0) {

                    printf ("\nPartida do computador...\n");
                    letra=2;casa=5;

                    /*a seguir, calcula-se uma operacao exponencial de base 3
                    com expoente "valor da posicao do tabuleiro", necessarios para verificar
                    cada informacao que esta contido nas posicoes do tabuleiro*/
                    base=1;
                    for (cont=0;cont<casa;cont++) base=base*3;

                    /*cada "casa" tera uma variavel de A a I,
                    em que cada letra ira receber o valor da letra indicada pelo jogador*/
                    if (casa==0)    A=letra;
                    if (casa==1)    B=letra;
                    if (casa==2)    C=letra;
                    if (casa==3)    D=letra;
                    if (casa==4)    E=letra;
                    if (casa==5)    F=letra;
                    if (casa==6)    G=letra;
                    if (casa==7)    H=letra;
                    if (casa==8)    I=letra;

                    /*Operacao para codificacao do tabuleiro e "resto" que indicara
                    a informacao contida no "total"*/
                    total=A*1+B*3+C*9+D*27+E*81+F*243+G*729+H*2187+I*6561;
                    resto=total/base%3;

                    /*impressao do tabuleiro*/
                    /*para cada letra que contem uma informacao, seja vazia, S ou O, deve
                    ser impresso a situacao presente*/
                    if (letra==resto)    {
                        if (A==0)   printf("     |");
                        if (A==1)   printf("  S  |");
                        if (A==2)   printf("  O  |");
                        if (B==0)   printf("     |");
                        if (B==1)   printf("  S  |");
                        if (B==2)   printf("  O  |");
                        if (C==0)   printf("     \n-----+-----+-----\n");
                        if (C==1)   printf("  S  \n-----+-----+-----\n");
                        if (C==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 1*/
                        if (D==0)   printf("     |");
                        if (D==1)   printf("  S  |");
                        if (D==2)   printf("  O  |");
                        if (E==0)   printf("     |");
                        if (E==1)   printf("  S  |");
                        if (E==2)   printf("  O  |");
                        if (F==0)   printf("     \n-----+-----+-----\n");
                        if (F==1)   printf("  S  \n-----+-----+-----\n");
                        if (F==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 2*/
                        if (G==0)   printf("     |");
                        if (G==1)   printf("  S  |");
                        if (G==2)   printf("  O  |");
                        if (H==0)   printf("     |");
                        if (H==1)   printf("  S  |");
                        if (H==2)   printf("  O  |");
                        if (I==0)   printf("     \n");
                        if (I==1)   printf("  S  \n");
                        if (I==2)   printf("  O  \n");
                    }
                    /*termino da jogada do computador, portanto, adiciona-se uma partida ("round") realizada*/
                    round++;
                    /*"turn" recebe informacao de que proxima jogada deve ser humana*/
                    turn=human_turn;
                }

                if (turn==robot_turn && A!=0 && B!=0 && C!=0 && D!=0 && E!=0 && F!=0 && G==0) {

                    printf ("\nPartida do computador...\n");
                    letra=1;casa=6;

                    /*a seguir, calcula-se uma operacao exponencial de base 3
                    com expoente "valor da posicao do tabuleiro", necessarios para verificar
                    cada informacao que esta contido nas posicoes do tabuleiro*/
                    base=1;
                    for (cont=0;cont<casa;cont++) base=base*3;

                    /*cada "casa" tera uma variavel de A a I,
                    em que cada letra ira receber o valor da letra indicada pelo jogador*/
                    if (casa==0)    A=letra;
                    if (casa==1)    B=letra;
                    if (casa==2)    C=letra;
                    if (casa==3)    D=letra;
                    if (casa==4)    E=letra;
                    if (casa==5)    F=letra;
                    if (casa==6)    G=letra;
                    if (casa==7)    H=letra;
                    if (casa==8)    I=letra;

                    /*Operacao para codificacao do tabuleiro e "resto" que indicara
                    a informacao contida no "total"*/
                    total=A*1+B*3+C*9+D*27+E*81+F*243+G*729+H*2187+I*6561;
                    resto=total/base%3;

                    /*impressao do tabuleiro*/
                    /*para cada letra que contem uma informacao, seja vazia, S ou O, deve
                    ser impresso a situacao presente*/
                    if (letra==resto)    {
                        if (A==0)   printf("     |");
                        if (A==1)   printf("  S  |");
                        if (A==2)   printf("  O  |");
                        if (B==0)   printf("     |");
                        if (B==1)   printf("  S  |");
                        if (B==2)   printf("  O  |");
                        if (C==0)   printf("     \n-----+-----+-----\n");
                        if (C==1)   printf("  S  \n-----+-----+-----\n");
                        if (C==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 1*/
                        if (D==0)   printf("     |");
                        if (D==1)   printf("  S  |");
                        if (D==2)   printf("  O  |");
                        if (E==0)   printf("     |");
                        if (E==1)   printf("  S  |");
                        if (E==2)   printf("  O  |");
                        if (F==0)   printf("     \n-----+-----+-----\n");
                        if (F==1)   printf("  S  \n-----+-----+-----\n");
                        if (F==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 2*/
                        if (G==0)   printf("     |");
                        if (G==1)   printf("  S  |");
                        if (G==2)   printf("  O  |");
                        if (H==0)   printf("     |");
                        if (H==1)   printf("  S  |");
                        if (H==2)   printf("  O  |");
                        if (I==0)   printf("     \n");
                        if (I==1)   printf("  S  \n");
                        if (I==2)   printf("  O  \n");
                    }
                    /*termino da jogada do computador, portanto, adiciona-se uma partida ("round") realizada*/
                    round++;
                    /*"turn" recebe informacao de que proxima jogada deve ser humana*/
                    turn=human_turn;
                }

                if (turn==robot_turn && A!=0 && B!=0 && C!=0 && D!=0 && E!=0 && F!=0 && G!=0 && H==0) {

                    printf ("\nPartida do computador...\n");
                    letra=2;casa=7;

                    /*a seguir, calcula-se uma operacao exponencial de base 3
                    com expoente "valor da posicao do tabuleiro", necessarios para verificar
                    cada informacao que esta contido nas posicoes do tabuleiro*/
                    base=1;
                    for (cont=0;cont<casa;cont++) base=base*3;

                    /*cada "casa" tera uma variavel de A a I,
                    em que cada letra ira receber o valor da letra indicada pelo jogador*/
                    if (casa==0)    A=letra;
                    if (casa==1)    B=letra;
                    if (casa==2)    C=letra;
                    if (casa==3)    D=letra;
                    if (casa==4)    E=letra;
                    if (casa==5)    F=letra;
                    if (casa==6)    G=letra;
                    if (casa==7)    H=letra;
                    if (casa==8)    I=letra;

                    /*Operacao para codificacao do tabuleiro e "resto" que indicara
                    a informacao contida no "total"*/
                    total=A*1+B*3+C*9+D*27+E*81+F*243+G*729+H*2187+I*6561;
                    resto=total/base%3;

                    /*impressao do tabuleiro*/
                    /*para cada letra que contem uma informacao, seja vazia, S ou O, deve
                    ser impresso a situacao presente*/
                    if (letra==resto)    {
                        if (A==0)   printf("     |");
                        if (A==1)   printf("  S  |");
                        if (A==2)   printf("  O  |");
                        if (B==0)   printf("     |");
                        if (B==1)   printf("  S  |");
                        if (B==2)   printf("  O  |");
                        if (C==0)   printf("     \n-----+-----+-----\n");
                        if (C==1)   printf("  S  \n-----+-----+-----\n");
                        if (C==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 1*/
                        if (D==0)   printf("     |");
                        if (D==1)   printf("  S  |");
                        if (D==2)   printf("  O  |");
                        if (E==0)   printf("     |");
                        if (E==1)   printf("  S  |");
                        if (E==2)   printf("  O  |");
                        if (F==0)   printf("     \n-----+-----+-----\n");
                        if (F==1)   printf("  S  \n-----+-----+-----\n");
                        if (F==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 2*/
                        if (G==0)   printf("     |");
                        if (G==1)   printf("  S  |");
                        if (G==2)   printf("  O  |");
                        if (H==0)   printf("     |");
                        if (H==1)   printf("  S  |");
                        if (H==2)   printf("  O  |");
                        if (I==0)   printf("     \n");
                        if (I==1)   printf("  S  \n");
                        if (I==2)   printf("  O  \n");
                    }
                    /*termino da jogada do computador, portanto, adiciona-se uma partida ("round") realizada*/
                    round++;
                    /*"turn" recebe informacao de que proxima jogada deve ser humana*/
                    turn=human_turn;
                }

                if (turn==robot_turn && A!=0 && B!=0 && C!=0 && D!=0 && E!=0 && F!=0 && G!=0 && H!=0 && I==0) {

                    printf ("\nPartida do computador...\n");
                    letra=1;casa=8;

                    /*a seguir, calcula-se uma operacao exponencial de base 3
                    com expoente "valor da posicao do tabuleiro", necessarios para verificar
                    cada informacao que esta contido nas posicoes do tabuleiro*/
                    base=1;
                    for (cont=0;cont<casa;cont++) base=base*3;

                    /*cada "casa" tera uma variavel de A a I,
                    em que cada letra ira receber o valor da letra indicada pelo jogador*/
                    if (casa==0)    A=letra;
                    if (casa==1)    B=letra;
                    if (casa==2)    C=letra;
                    if (casa==3)    D=letra;
                    if (casa==4)    E=letra;
                    if (casa==5)    F=letra;
                    if (casa==6)    G=letra;
                    if (casa==7)    H=letra;
                    if (casa==8)    I=letra;

                    /*Operacao para codificacao do tabuleiro e "resto" que indicara
                    a informacao contida no "total"*/
                    total=A*1+B*3+C*9+D*27+E*81+F*243+G*729+H*2187+I*6561;
                    resto=total/base%3;

                    /*impressao do tabuleiro*/
                    /*para cada letra que contem uma informacao, seja vazia, S ou O, deve
                    ser impresso a situacao presente*/
                    if (letra==resto)    {
                        if (A==0)   printf("     |");
                        if (A==1)   printf("  S  |");
                        if (A==2)   printf("  O  |");
                        if (B==0)   printf("     |");
                        if (B==1)   printf("  S  |");
                        if (B==2)   printf("  O  |");
                        if (C==0)   printf("     \n-----+-----+-----\n");
                        if (C==1)   printf("  S  \n-----+-----+-----\n");
                        if (C==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 1*/
                        if (D==0)   printf("     |");
                        if (D==1)   printf("  S  |");
                        if (D==2)   printf("  O  |");
                        if (E==0)   printf("     |");
                        if (E==1)   printf("  S  |");
                        if (E==2)   printf("  O  |");
                        if (F==0)   printf("     \n-----+-----+-----\n");
                        if (F==1)   printf("  S  \n-----+-----+-----\n");
                        if (F==2)   printf("  O  \n-----+-----+-----\n");       /*fim da linha 2*/
                        if (G==0)   printf("     |");
                        if (G==1)   printf("  S  |");
                        if (G==2)   printf("  O  |");
                        if (H==0)   printf("     |");
                        if (H==1)   printf("  S  |");
                        if (H==2)   printf("  O  |");
                        if (I==0)   printf("     \n");
                        if (I==1)   printf("  S  \n");
                        if (I==2)   printf("  O  \n");
                    }
                    /*termino da jogada do computador, portanto, adiciona-se uma partida ("round") realizada*/
                    round++;
                    /*"turn" recebe informacao de que proxima jogada deve ser humana*/
                    turn=human_turn;
                }

                /*Inicia-se a seguir se cada jogada realizada pelo computador
                formou um SOS valido. Para cada casa, ha um certo numero de SOSs validos.
                Por exemplo, na primeira casa, poderao formar 3 SOSs: uma horizontal, uma vertical e uma diagonal*/
                /*cada SOS formado, serao adicionados pontos ("points")*/
                if (casa==0)    {
                    if (A==1 && B==2 && C==1)   points++;
                    if (A==1 && E==2 && I==1)   points++;
                    if (A==1 && D==2 && G==1)   points++;
                }
                if (casa==1)    {
                    if (A==1 && B==2 && C==1)   points++;
                    if (B==1 && E==2 && H==1)   points++;
                }
                if (casa==2)    {
                    if (A==1 && B==2 && C==1)   points++;
                    if (C==1 && E==2 && G==1)   points++;
                    if (C==1 && F==2 && I==1)   points++;
                }
                if (casa==3)    {
                    if (D==1 && E==2 && F==1)   points++;
                    if (A==1 && D==2 && G==1)   points++;
                }
                if (casa==4)    {
                    if (D==1 && E==2 && F==1)   points++;
                    if (A==1 && E==2 && I==1)   points++;
                    if (B==1 && E==2 && H==1)   points++;
                    if (C==1 && E==2 && G==1)   points++;
                }
                if (casa==5)    {
                    if (D==1 && E==2 && F==1)   points++;
                    if (C==1 && F==2 && I==1)   points++;
                }
                if (casa==6)    {
                    if (G==1 && H==2 && I==1)   points++;
                    if (C==1 && E==2 && G==1)   points++;
                    if (A==1 && D==2 && G==1)   points++;
                }
                if (casa==7)    {
                    if (G==1 && H==2 && I==1)   points++;
                    if (B==1 && E==2 && H==1)   points++;
                }
                if (casa==8)    {
                    if (G==1 && H==2 && I==1)   points++;
                    if (A==1 && E==2 && I==1)   points++;
                    if (C==1 && F==2 && I==1)   points++;
                }

                /*os "points" serao adicionados ao ponto do jogador atual ("ptos_robot")*/
                ptos_robot+=points;

                /*caso foi realizado ao menos um ponto, o jogador atual recebe mais uma partida,
                neste caso, "turn" indicara ao programa pular para a jogada do computador, novamente*/
                if (points>0)   turn=robot_turn;

                /*"points" volta a zerar, para nao entrar em conflito com a jogada do computador*/
                points=0;

                /*pontos efetuados pelo humano e pelo computador serao guardados e somados na variavel "sos"*/
                sos=ptos_robot+ptos_human;
                printf ("Ha %d SOS(s) formado(s)\nPontos: HUMANO %d X %d COMPUTADOR\n",sos,ptos_human,ptos_robot);
            }
            erro=sem_erro; /*caso a jogada humana tiver sido invalida, o programa volta para o comeco*/
        }

    /*Apos o programa sair do "looping", ocorre a seguir a comparacao do placar, indicando qual dos jogadores ganhou, ou se houve empate*/
    if  (ptos_human>ptos_robot)     printf("::::::::::Computador derrotado! Vitoria do humano!::::::::::\n");
    else                            printf("::::::::::Humano derrotado! Vitoria do computador!::::::::::\n");
    if  (ptos_human==ptos_robot)    printf("::::::::::Empate!!::::::::::\n");

    return 0;
}
