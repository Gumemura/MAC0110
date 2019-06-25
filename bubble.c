#include <stdio.h>

#define MAX 10

void bubbleSort(int vector[]){

	for(int it = 0; it < MAX; it++){
		for(int aBS = 0; aBS < MAX; aBS++){
			int ar;
			if(vector[aBS] > vector[aBS + 1]){
				ar = vector[aBS];
				vector[aBS] = vector[aBS + 1];
				vector[aBS + 1] = ar;
			}
		}
	}
}

//Exemplo

int main(){
	int a[MAX] = {9, 0, 6, 3, 7, 8, 2, 1, 4, 5};

	bubbleSort(a);

	printf("Output desejado: 1 2 3 4 5 5 6 7 8 9\n");

	for (int i = 0; i < MAX; i++){
		printf("%d\n", a[i]);
	}

}