#include <stdio.h> 
int main()
{
    char letra; 
    int maior, tamatual; 
    maior = 0; 
    tamatual = 0;
    scanf("%c", &letra);
    while (letra != '.'){
        if (letra != ' ')
            tamatual++;
        else{
            if (tamatual > maior)
	           maior = tamatual;
            tamatual = 0;
        }
        printf("aa ");
        scanf("%c", &letra);
    }
    if (tamatual > maior)
        maior = tamatual;
    printf("A maior palavra tem %d letras\n", maior);
    return 0;
}