#include <stdio.h>
//#include <stdlib.h>

#define MAX 10

void ordena(int a[], int quant){
	int v[MAX], menor, cont = 0;
		menor = a[roda];

		for (int i = roda; i < MAX; i++){
			if(menor > a[i]){
				menor = a[i];
			}
		}

		v[cont] = menor;
		cont++;
	}

	for (int i = 0; i < MAX; ++i){
		a[i] = v[i];
	}
}


int main(){
	int vec[9] = {4, 3, 7, 6, 3, 2, 12, 9, 3};

	ordena(vec, 9);

	for (int i = 0; i < 9; ++i){
		printf("%d\n", vec[i]);
	}
}


/*	0  1  2  3  4  5  6   7  8  

0	4, 3, 7, 6, 3, 2, 12, 9, 3

I 	2, 3, 7, 6, 3, 4, 12, 9, 3

II	2, 3, 7, 6, 3, 4, 12, 9, 3*/