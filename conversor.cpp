#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int decToHex(int Dec);
int decToBin(int Dec);
int decToBin1(int Dec);
int decToBin2(int Dec);
int hexToDec(char Hex[5]);
int binToDec(char binarios[16]);
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
      printf("\n    Para o bom funcionamento dessa função, foi colocado um limite que permite até o número \'+7FFF\' e \'-7FFF\'.\n    Pois, o número 7FFF vai até o Decimal 32767, limite no preenchimento de 15bits.\n    Deixando assim, um livre para o sinal magnitude.\n    Se for utilizar apenas um número exemplo: \'F\', coloque três 0 a frente e o sinal de positivo, exemplo: \'+000F\'\n    Agora que já deixamos claro, Digite o seu numero: ");
      char Hex[2];
      scanf("%s", Hex);
      int toDec;
      toDec = hexToDec(Hex);
      printf("\n        Seu número em decimal é: %d\n",toDec);
      decToBin(toDec);
      decToBin1(toDec);
      decToBin2(toDec);
      printf("\n");
      break;
    case 3:
      char binarios[16];
      scanf("%s",binarios);
      int bindec;
      bindec = binToDec(binarios);
      printf("\n        Seu número em decimal é: %d",bindec);
      decToHex(bindec);
      decToBin1(bindec);
      decToBin2(bindec);
      printf("\n");
      break;
    case 4:
      break;
    case 5:
      break;
    }
    system("PAUSE");
}
int decToHex(int Dec){
  int resto, quociente=Dec;
	char hexa[5]={0};
	if(quociente<0){
        hexa[4]='-';
        quociente=abs(quociente);
	}else{
        hexa[4]='+';
	}

  for(int i =0 ;i<4;i++){
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
  for(int j = 4; j>=0; j--){
    printf("%c", hexa[j]);
  }
  printf("\n");
  return 0;
}
int decToBin(int Dec){
  int resto, quociente = Dec;
	char bin1[17]={0};
	if(quociente<0){
        bin1[15]=49;
        quociente=abs(quociente);
	}else{
        bin1[15]='0';
    }

  for(int i =0 ;i<=14;i++){
    resto = quociente%2;
    quociente /= 2;
    bin1[i]=resto+48;
  }

  printf("        Seu número em binario é:");
  for(int j = 16; j>=0; j--){
    printf("%c", bin1[j]);
  }
  printf("\n");
  return 0;
}
int decToBin1(int Dec){
  int resto, quociente = Dec;
	char bin1[16]={0};
	if(quociente<0){
        bin1[15]='0';
        quociente=abs(quociente);
	}else {
        bin1[15]='1';
	}
  for(int i =0 ;i<=14;i++){
    resto = quociente%2;
    quociente /= 2;
     if(resto==0){
      bin1[i]=49;
    }else if(resto!=0){
      bin1[i]=48;
    }
  }
  printf("        Seu número em binario complemento de 1 é: ");
  for(int j = 15; j>=0; j--){
    printf("%c", bin1[j]);
  }
  printf("\n");
  return 0;
}
int decToBin2(int Dec){
    int resto, quociente1=Dec;
	char bin2[16]={0};
	if(quociente1<0){
        bin2[15]='0';
        quociente1=abs(quociente1);
	}else {
        bin2[15]='1';
	}
  for(int i =0 ;i<=14;i++){
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
  for(int i = 0;i<=14;i++){
    if(bin2[i]==50){
      bin2[i]=48;
      if(i==14){
        break;
      }
      if(bin2[i+1]==49){
        bin2[i+1]=50;
      }else if (bin2[i+1]==48){
        bin2[i+1]=49;
      }
    }
  }

  printf("        Seu número em binario Complemento de 2 é: ");
  for(int j = 15; j>=0; j--){
    printf("%c", bin2[j]);
  }
  printf("\n");
  return 0;
}
int hexToDec(char Hex[5]){
  char hex[5],aux;
  strcpy(hex,Hex);
  int total=0, inter=0;
  if(hex[0]=='-'){
    inter=1;
  }
  aux=hex[1];
  hex[1]=hex[4];
  hex[4]=aux;
  aux=hex[2];
  hex[2]=hex[3];
  hex[3]=aux;
  for(int i = 1;i<=4;i++){
    if(hex[i]=='A'){
      total += 10*pow(16,i-1);
    }else if(hex[i]=='B'){
      total += 11*pow(16,i-1);
    }else if(hex[i]=='C'){
      total += 12*pow(16,i-1);
    }else if(hex[i]=='D'){
      total += 13*pow(16,i-1);
    }else if(hex[i]=='E'){
      total += 14*pow(16,i-1);
    }else if(hex[i]=='F'){
      total += 15*pow(16,i-1);
    }else if(hex[i]=='0'){
      total += 0*pow(16,i-1);
    }else if(hex[i]=='1'){
      total += 1*pow(16,i-1);
    }else if(hex[i]=='2'){
      total += 2*pow(16,i-1);
    }else if(hex[i]=='3'){
      total += 3*pow(16,i-1);
    }else if(hex[i]=='4'){
      total += 4*pow(16,i-1);
    }else if(hex[i]=='5'){
      total += 5*pow(16,i-1);
    }else if(hex[i]=='6'){
      total += 6*pow(16,i-1);
    }else if(hex[i]=='7'){
      total += 7*pow(16,i-1);
    }else if(hex[i]=='8'){
      total += 8*pow(16,i-1);
    }else if(hex[i]=='9'){
      total += 9*pow(16,i-1);
    }
  }
  if(inter==1){
  return -1*total;
  }
  return total;
}
int binToDec(char binarios[16]){
  int total=0,aux,j=0;
    char bin[16];
    strcpy(bin,binarios);
    for(int i=15; i>0;i--){
        if(bin[i]=='1'){
            total += pow(2,j);
        }
        j++;
    }
    if(bin[0]=='1'){
        return -1*total;
    }
    return total;
}
int bin1ToDec(){
  return 0;
}
int bin2ToDec(){
  return 0;
}
