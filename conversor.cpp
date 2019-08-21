#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

int decToHex(int Dec);
int decToBin(int Dec);
int decToBin1(int Dec);
int decToBin2(int Dec);
int hexToDec(char Hex[2]);
int binToDec();
int bin1ToDec();
int bin2ToDec();


int main(){
  setlocale(LC_ALL, "Portuguese Brasil");
    int indice;
    printf("    Qual base você gostaria de converter? Digite o respectivo indice. \n");
    printf("    1 - Decimal, 2 - Hexadecimal, 3 Binario, 4 - Binario Complemento de 1, 5 - Binario Complemento de 2. \n\n        ");
    scanf("%d", &indice);
    switch (indice)
    {
    case 1:
      printf("\n    Agora digite o número que deseja converter: ");
      int Dec;
      scanf("%d",&Dec);
      decToHex(Dec);
      decToBin(Dec);
      decToBin1(Dec);
      decToBin2(Dec);
      break;
    case 2:
      printf("\n    Para o bom funcionamento dessa função, foi colocado um limite que permite até o número \'FF\'.\n    Pois, o número FF vai até o Decimal 255, limite no preenchimento de 1byte.\n    Se for utilizar apenas um número exemplo: \'F\', coloque um 0 a frente, exemplo: \'0F\'\n    Agora que já deixamos claro, Digite o seu numero: ");
      char Hex[2];
      scanf("%s", Hex);
      int toDec;
      toDec = hexToDec(Hex);
      printf("\n        Seu número em decimal é: %d\n",toDec);
      decToBin(toDec);
      decToBin1(toDec);
      decToBin2(toDec);
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    }
}
int decToHex(int Dec){
  int resto, quociente=Dec;
	char hexa[9]={0};

  for(int i =0 ;i<=8;i++){
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
  printf("\n        Seu número em HexaDecimal é: ");
  for(int j = 1; j>=0; j--){
    printf("%c", hexa[j]);
  }
  printf("\n");
  return 0;
}
int decToBin(int Dec){
  int resto, quociente = Dec;
	char bin1[9]={0};

  for(int i =0 ;i<=8;i++){
    resto = quociente%2;
    quociente /= 2;
    bin1[i]=resto+48;
  }
  printf("        Seu número em binario é: ");
  for(int j = 7; j>=0; j--){
    printf("%c", bin1[j]);
  }
  printf("\n");
  return 0;
}
int decToBin1(int Dec){
  int resto, quociente = Dec;
	char bin1[9]={0};
  for(int i =0 ;i<=8;i++){
    resto = quociente%2;
    quociente /= 2;
     if(resto==0){
      bin1[i]=49;
    }else if(resto!=0){
      bin1[i]=48;
    }
  }
  printf("        Seu número em binario complemento de 1 é: ");
  for(int j = 7; j>=0; j--){
    printf("%c", bin1[j]);
  }
  printf("\n");
  return 0;
}
int decToBin2(int Dec){
    int resto, quociente1=Dec;
	char bin2[9]={0};
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

  printf("        Seu número em binario Complemento de 2 é: ");
  for(int j = 7; j>=0; j--){
    printf("%c", bin2[j]);
  }
  printf("\n");
  return 0;
}
int hexToDec(char Hex[2]){
  char hex[2],aux;
  strcpy(hex,Hex);
  int total=0;
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
  return total;
}
int binToDec(){
  return 0;
}
int bin1ToDec(){
  return 0;
}
int bin2ToDec(){
  return 0;
}