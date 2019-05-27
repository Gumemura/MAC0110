#include <stdio.h>

#define MAX 30

int incidenciasVC[MAX];

int temX(int *arrayInt[], *valorChecado){
	int cont = 1;

	for(int q = 0; q < MAX; q++){
		if(*arrayInt[q] == *valorChecado){
			incidenciasVC[cont] = q;
			cont++;
			return 1;
		}else{
			return -1;
		}
	}
}


int main(){

}