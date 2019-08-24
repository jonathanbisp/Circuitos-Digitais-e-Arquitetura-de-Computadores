#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
  int resto, quociente;
	char hexa[11]={0};
  scanf("%d",&quociente);

  for(int i =0 ;i<=10;i++){
    resto = quociente%16;
    quociente /= 16;
    
    if(resto==10){
      strcat(hexa,"A");
    }else if(resto==11){
      strcat(hexa,"B");
    }else if(resto==12){
      strcat(hexa,"C");
    }else if(resto==13){
      strcat(hexa,"D");
    }else if(resto==14){
      strcat(hexa,"E");
    }else if(resto==15){
      strcat(hexa,"F");
    }else {
      hexa[i]=resto+48;
    }
  }

  for(int j = (strlen(hexa)); j>=0; j--){
    printf("%c", hexa[j]);
  }
}