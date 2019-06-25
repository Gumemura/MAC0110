#include <stdio.h>
//#include <stdlib.h>

#define MAX 100

void ordena(int a[]){
  int menor = a[0], cont = 0, ar;

  for(int roda = 0; roda < 5; roda++){
    if(menor > a[roda]){
      menor = a[roda];
    }
  }
}


int main(){
  int vec[5] = {4, 3, 7, 6, 2};

  ordena(vec);

  for (int i = 0; i < 5; ++i){
    printf("%d\n", vec[i]);
  }


}