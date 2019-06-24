#include <stdio.h>

#define MAX 10

void bubbleSort(int vector[]){

	while(){
		for(int aBS = 0; aBS < MAX; aBS++){
			if(vector[aBS] > vector[aBS + 1])
				vector[aBS] = vector[aBS + 1];

		}
	}
}

//Exemplo

int main(){
	int a[10] = {9, 5, 6, 3, 7, 8, 2, 1, 4, 5};

	bubbleSort(a);

	for (int i = 0; i < MAX; i++){
		printf("%d\n", a[i]);
	}

}