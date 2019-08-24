#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
  int resto, quociente1;
	char bin2[9]={0};
  scanf("%d",&quociente1);

  for(int i =0 ;i<=8;i++){
    resto = quociente1%2;
    quociente1 /= 2;
    if(resto==0){
      bin2[i]=49;
    }else if(resto!=0){
      bin2[i]=48;
    }
  }
 if(bin2[0]==48){
   bin2[0]=49;
 }else if(bin2[0]==49){
   bin2[0]=50;
 }

  for(int i = 0;i<=8;i++){
    if(bin2[i]==50){
      bin2[i]=48;
      if(bin2[i+1]==49){
        bin2[i+1]=50;
      }else if (bin2[i+1]==48){
        bin2[i+1]=49;
      }
    }
  }

  printf("Seu numero em binario Complemento de 2 eh: ");
  for(int j = (strlen(bin2)); j>=0; j--){
    printf("%c", bin2[j]);
  }
  printf("\n");
}