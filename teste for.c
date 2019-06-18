#include <stdio.h>

int main(){
	int v[8][8];

	for(int a = 0; a < 8; a++){
		for(int b = 0; b < 8; b++){
			v[a][b] = 0;
		}
	}
	v[0][2] = 2;

	for(int a = 0; a < 8; a++){
		for(int b = 0; b < 8; b++){
			printf("v[%d][%d] = %d\n", a, b, v[a][b]);
		}
	}

	return 0;
}