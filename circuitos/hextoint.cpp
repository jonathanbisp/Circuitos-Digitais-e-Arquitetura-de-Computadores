#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>

int main(){
  char hex[2],aux;
  int total=0;
  scanf("%s",hex);
  aux=hex[0];
  hex[0]=hex[1];
  hex[1]=aux;
  for(int i = 0;i<=1;i++){
    if(hex[i]=='A'){
      total += 10*pow(16,i);
    }else if(hex[i]=='B'){
      total += 11*pow(16,i);
    }else if(hex[i]=='C'){
      total += 12*pow(16,i);
    }else if(hex[i]=='D'){
      total += 13*pow(16,i);
    }else if(hex[i]=='E'){
      total += 14*pow(16,i);
    }else if(hex[i]=='F'){
      total += 15*pow(16,i);
    }else if(hex[i]=='0'){
      total += 0 * pow(16,i);
    }else if(hex[i]=='1'){
      total += 1*pow(16,i);
    }else if(hex[i]=='2'){
      total += 2*pow(16,i);
    }else if(hex[i]=='3'){
      total += 3*pow(16,i);
    }else if(hex[i]=='4'){
      total += 4*pow(16,i);
    }else if(hex[i]=='5'){
      total += 5*pow(16,i);
    }else if(hex[i]=='6'){
      total += 6*pow(16,i);
    }else if(hex[i]=='7'){
      total += 7*pow(16,i);
    }else if(hex[i]=='8'){
      total += 8*pow(16,i);
    }else if(hex[i]=='9'){
      total += 9*pow(16,i);
    }
  }
  printf("%d",total);
  return total;
}