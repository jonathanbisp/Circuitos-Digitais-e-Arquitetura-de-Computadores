#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
  int resto, quociente;
	char bin1[22]={0};
  scanf("%d",&quociente);

  for(int i =0 ;i<=20;i++){
    resto = quociente%2;
    quociente /= 2;
     if(resto==0){
      bin1[i]=49;
    }else if(resto!=0){
      bin1[i]=48;
    }
  }
  printf("Seu numero em binario Complemento de 1 eh: ");
  for(int j = (strlen(bin1)); j>=0; j--){
    printf("%c", bin1[j]);
  }
  printf("\n");
}