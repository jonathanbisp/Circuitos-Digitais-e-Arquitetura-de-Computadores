#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

//DECLARAÇÃO DAS FUNÇÕES RECURSIVAS QUE USAREMOS
int decToHex(int Dec);
int decToBin(int Dec);
int decToBin1(int Dec);
int decToBin2(int Dec);
int hexToDec(char Hex[5]);
int binToDec(char Bin[16]);
int bin1ToDec(char Bin1[16]);
int bin2ToDec(char Bin2[16]);


int main(){

    //PERMITE USAR OS CARACTERES DO UTF-8
    setlocale(LC_ALL, "Portuguese Brasil");

    int indice;
    printf("    Qual base você gostaria de converter? Digite o respectivo indice. \n");
    printf("    1 - Decimal, 2 - Hexadecimal, 3 - Binario, 4 - Binario Complemento de 1, 5 - Binario Complemento de 2. \n\n        ");
    scanf("%d", &indice);

    switch (indice){

        case 1:

            //EXPLICAÇÃO DO FUNCIONAMENTO E LIMITAÇÕES DO ALGORITMO
            printf("\n    Para o bom funcionamento dessa função, foi colocado um limite que permite até os números \'+32767\' e \'-32767\'.\n    Pois, o número 32767 vai até o limite no preenchimento de 15bits.\n    Deixando assim, um livre um bit para o sinal magnitude.\n    Se for utilizar apenas um número exemplo: \'7\', coloque quatro 0 a frente e o sinal de positivo, exemplo: \'+00007\'\n    Agora que já deixamos claro, Digite o seu numero: ");
            int Dec;
            scanf("%d",&Dec);

            //CHAMA AS FUNÇÕES DE CONVERSAO, UTILIZANDO DEC COMO PARAMETRO
            decToHex(Dec);
            decToBin(Dec);
            decToBin1(Dec);
            decToBin2(Dec);
            break;

        case 2:

            //EXPLICAÇÃO DO FUNCIONAMENTO E LIMITAÇÕES DO ALGORITMO
            printf("\n    Para o bom funcionamento dessa função, foi colocado um limite que permite até os números \'+7FFF\' e \'-7FFF\'.\n    Pois, o número 7FFF vai até o Decimal 32767, limite no preenchimento de 15bits.\n    Deixando assim, um livre um bit para o sinal magnitude.\n\n    Se for utilizar apenas um número exemplo: \'F\', coloque três 0 a frente e o sinal de positivo, exemplo: \'+000F\'\n    Agora que já deixamos claro, Digite o seu numero: ");
            char Hex[5];
            scanf("%s", Hex);
            int toDec;

            //PARA REDUZIR O CODIGO, É CHAMADO O RETORNO DE HEXTODEC, QUE É UM INTEIRO EQUIVALENTE, EM SEGUIDA É UTILIIADO COMO PARAMETRO
            toDec = hexToDec(Hex);
            printf("\n        Seu número em decimal é: %d\n",toDec);

            //CHAMA AS FUNÇÕES DE CONVERSAO, UTILIZANDO TODEC COMO PARAMETRO
            decToBin(toDec);
            decToBin1(toDec);
            decToBin2(toDec);
            printf("\n");
            break;

        case 3:
            char bin0[16];
            //EXPLICAÇÃO DO FUNCIONAMENTO E LIMITAÇÕES DO ALGORITMO
            printf("\n    Para o bom funcionamento dessa função,\n    Foi colocado um limite que permite até os números \'1111111111111111\' e \'0111111111111111\'.\n    Pois, o número 0111111111111111 vai até o Decimal 32767, limite no preenchimento de 15bits.\n    Deixando assim, um livre um bit para o sinal magnitude.\n    Se for utilizar apenas um número exemplo: \'1\', coloque quartoze 0 a frente e o sinal de magnitude,\n    Sendo que deve utilizar o 0 para positivo e 1 para negativo, exemplo: \'1000000000000011\' para \'-3\'\n    Agora que já deixamos claro, Digite o seu numero: ");
            scanf("%s",bin0);
            int bindec;

            //COMO NO CASO ACIMA, É UTILIZADO PARA REDUZIR O CODIGO, RETORNANDO UM INTEIRO EQUIVALENTE QUE PODE SER UTILIZADO COMO PARAMETRO
            bindec = binToDec(bin0);
            printf("\n        Seu número em decimal é: %d",bindec);

            //CHAMA AS FUNÇÕES DE CONVERSAO, UTILIZANDO BINDEC COMO PARAMETRO
            decToHex(bindec);
            decToBin1(bindec);
            decToBin2(bindec);
            printf("\n\n");
            break;

        case 4:
            //EXPLICAÇÃO DO FUNCIONAMENTO E LIMITAÇÕES DO ALGORITMO
            printf("\n    Para o bom funcionamento dessa função,\n    Foi colocado um limite que permite até os números \'1111111111111111\' e \'0111111111111111\'.\n    Pois, o número 0111111111111111 vai até o Decimal 32767, limite no preenchimento de 15bits.\n    Deixando assim, um livre um bit para o sinal magnitude.\n    Se for utilizar apenas um número exemplo: \'1\', coloque quartoze 0 a frente e o sinal de magnitude,\n    Sendo que deve utilizar o 0 para positivo e 1 para negativo, exemplo: \'1000000000000011\' para \'3\'\n    Agora que já deixamos claro, Digite o seu numero: ");
            char bin1[16];
            scanf("%s",bin1);
            int bin1dec;

            //COMO NO CASO ACIMA, É UTILIZADO PARA REDUZIR O CODIGO, RETORNANDO UM INTEIRO EQUIVALENTE QUE PODE SER UTILIZADO COMO PARAMETRO
            bin1dec = bin1ToDec(bin1);
            printf("\n        Seu número em decimal é: %d",bin1dec);

            //CHAMA AS FUNÇÕES DE CONVERSAO, UTILIZANDO BINDEC COMO PARAMETRO
            decToHex(bin1dec);
            decToBin(bin1dec);
            decToBin2(bin1dec);
            printf("\n\n");
            break;
        case 5:
            //EXPLICAÇÃO DO FUNCIONAMENTO E LIMITAÇÕES DO ALGORITMO
            printf("\n    Para o bom funcionamento dessa função,\n    Foi colocado um limite que permite até os números \'1111111111111111\' e \'0111111111111111\'.\n    Pois, o número 0111111111111111 vai até o Decimal 32767, limite no preenchimento de 15bits.\n    Deixando assim, um livre um bit para o sinal magnitude.\n    Se for utilizar apenas um número exemplo: \'1\', coloque quartoze 0 a frente e o sinal de magnitude,\n    Sendo que deve utilizar o 0 para positivo e 1 para negativo, exemplo: \'1111111111111101\' para \'3\'\n    Agora que já deixamos claro, Digite o seu numero: ");
            char bin2[16];
            scanf("%s",bin2);
            int bin2dec;

            //COMO NO CASO ACIMA, É UTILIZADO PARA REDUZIR O CODIGO, RETORNANDO UM INTEIRO EQUIVALENTE QUE PODE SER UTILIZADO COMO PARAMETRO
            bin2dec = bin2ToDec(bin2);
            printf("\n        Seu número em decimal é: %d",bin2dec);

            //CHAMA AS FUNÇÕES DE CONVERSAO, UTILIZANDO BINDEC COMO PARAMETRO
            decToHex(bin2dec);
            decToBin(bin2dec);
            decToBin1(bin2dec);
            printf("\n\n");
            break;
    }
    printf("                Powered by: Jonathan Bispo\n\n");
    system("PAUSE");
}

int decToHex(int Dec){

    //INICIALIZAÇÃO DOS VARIAVEIS, E PEGANDO O PARAMETRO
    int resto, quociente=Dec;
	char hexa[5]={0};

	//MECANISMO PARA PERMITIR RETORNAR UM VALOR POSITIVO OU NEGATIVO APARTIR DO PRIMEIRO DIGITO QUE PODE SER + OU -
	if(quociente<0){
        hexa[4]='-';
        quociente=abs(quociente);
	}else{
        hexa[4]='+';
	}

    //APARTIR DO SEGUNDO VALOR DO VETOR, JA QUE O PRIMEIRO É O SINAL DE MAGNITUDE, ATRIBUIMOS VAMORES HEXADECIMAL APARTIR DO SEU RESTO
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
  //COMO CALCULADOS O RESTO E O HEXADECIMAL É LIDO AO CONTRARIO QUANDO OBTIDO APARTIR DE UM RESTO, VAMOS IMPRIMIR AO CONTRARIO OS VALORES OBTIDOS
    for(int j = 4; j>=0; j--){
        printf("%c", hexa[j]);
    }
    printf("\n");
    return 0;
}

int decToBin(int Dec){
    //INICIALIZAÇÃO DOS VARIAVEIS, E PEGANDO O PARAMETRO
    int resto, quociente = Dec;
	char bin1[16]={0};

	//RECONHECE SE O NUMERO INTEIRO É POSITIVO OU NEGATIVO E EM SEGUIDA ORGANIZA O 15 ITEM DO VETOR PARA 1 OU 0 SINAIS DE AMPLITUDE
	if(quociente<0){
        bin1[15]=49;
        quociente=abs(quociente);
	}else{
        bin1[15]='0';
    }

    //DEFINE SE VAI SER 1 OU 0
    for(int i =0 ;i<=14;i++){
        resto = quociente%2;
        quociente /= 2;
        bin1[i]=resto+48;
    }

    printf("        Seu número em binario é: ");

  //IMPRIME AO CONTRARIO PARA ORDENAR CORRETAMENTE
    for(int j = 15; j>=0; j--){
        printf("%c", bin1[j]);
    }
    printf("\n");
    return 0;
}

int decToBin1(int Dec){
    //INICIALIZAÇÃO DOS VARIAVEIS, E PEGANDO O PARAMETRO
    int resto, quociente = Dec;
	char bin1[16]={0};

	//VERIFICA SE É POSITIVO OU NEGATIVO E ATRIBUI OS VALORES DE AMPLITUDE
	if(quociente<0){
        bin1[15]='0';
        quociente=abs(quociente);
	}else {
        bin1[15]='1';
	}

	//TRANSFORMA EM BINARIO E INVERTE OS VALORES, DE 0 PARA 1 E DE 1 PARA 0
    for(int i =0 ;i<=14;i++){
        resto = quociente%2;
        quociente /= 2;
        if(resto==0){
            bin1[i]='1';
        }else if(resto!=0){
            bin1[i]='0';
        }
    }
    printf("        Seu número em binario complemento de 1 é: ");

  //IMPRIME OS VALORES AOCONTRARIO JA QUE SÃO ADICIONADOS DE MANEIRA DECRESCENTE E O RESULTADO CERTO É DE MANEIRA CRESCENTE
    for(int j = 15; j>=0; j--){
        printf("%c", bin1[j]);
    }
    printf("\n");
    return 0;
}

int decToBin2(int Dec){

    //INICIALIZAÇÃO DOS VARIAVEIS, E PEGANDO O PARAMETRO
    int resto, quociente1=Dec;
	char bin2[16]={0};

    //VERIFICA SE É POSITIVO OU NEGATIVO E ATRIBUI OS VALORES DE AMPLITUDE
	if(quociente1<0){
        bin2[15]='0';
        quociente1=abs(quociente1);
	}else {
        bin2[15]='1';
	}

    //TRANSFORMA EM BINARIO E INVERTE OS VALORES, DE 0 PARA 1 E DE 1 PARA 0
    for(int i =0 ;i<=14;i++){
        resto = quociente1%2;
        quociente1 /= 2;
        if(resto==0){
            bin2[i]='1';
        }else if(resto!=0){
            bin2[i]='0';
        }
  }

    //SOMA UM NO ULTIMO VALOR
    if(bin2[0]==48){
        bin2[0]=49;
    }else if(bin2[0]==49){
        bin2[0]=50;
    }

    //DEFINE O LIMITE ATÉ A POSIÇÃO 14 PARA NÃO INTERVIR NO SINAL DE AMPLITUDE
    for(int i = 0;i<=14;i++){

        //MECANISMO PARA CONFERIR SE O A ATUAL POSIÇÃO VIROU 2 SE SIM PASSA O VALOR ATUAL PARA 0 SE NÃO QUEBRA O LAÇO
        if(bin2[i]==50){
            bin2[i]=48;
        if(i==14){
            break;
        }

        //SE PASSAR NO IF-ELSE ANTERIOR CONFERE SE O PROXIMO VALOR É 0 OU 1 E FAZ A ADIÇÃO PREPARANDO PARA A PROXIMA REPETIÇÃO
        if(bin2[i+1]==49){
            bin2[i+1]=50;
        }else if (bin2[i+1]==48){
            bin2[i+1]=49;
        }
        }
    }

    printf("        Seu número em binario Complemento de 2 é: ");

    //IMPRIME AO CONTRARIO PELOS MOTIVOS JA CITADOS ANTERIORMENTE
    for(int j = 15; j>=0; j--){
        printf("%c", bin2[j]);
    }
    printf("\n");
    return 0;
}

int hexToDec(char Hex[5]){

    //INICIALIZAÇÃO DOS VARIAVEIS, E PEGANDO O PARAMETRO
    char hex[5],aux;
    strcpy(hex,Hex);
    int total=0, inter=0;

    //MECANISMO PARA SABER SE É NEGATIVO OU POSITIVO
    if(hex[0]=='-'){
        inter=1;
    }

    //POR ALGUM MOTIVO EU TIVE QUE FAZER ISSO POR QUE TAVA SAINDO AO CONTRARIO.
    aux=hex[1];
    hex[1]=hex[4];
    hex[4]=aux;
    aux=hex[2];
    hex[2]=hex[3];
    hex[3]=aux;

    //MECANISMO DE CONVERSÃO DE DECIMAL PARA HEXA
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

    //APARTIR DO SINAL DEFINE SE VAI SER NEGATIVO OU POSITIVO
    if(inter==1){
        return -1*total;
    }
    return total;
}

int binToDec(char Bin[16]){

    //INICIALIZAÇÃO DOS VARIAVEIS, E PEGANDO O PARAMETRO
    int total=0,aux,j=0;
    char bin[16];
    strcpy(bin,Bin);

    //CONVERTE DE BINARIO PARA DECIMAL
    for(int i=15; i>0;i--){
        if(bin[i]=='1'){
            total += pow(2,j);
        }
        j++;
    }

    //VERIFICA SE O PRIMEIRO DIGITO É 1 POR CONTA DO SINAL DE AMPLITUDE E RETORNA O TOTAL POSITIVO OU NEGATIVO
    if(bin[0]=='1'){
        return -1*total;
    }
    return total;
}

int bin1ToDec(char Bin1[16]){

    //INICIALIZAÇÃO DOS VARIAVEIS, E PEGANDO O PARAMETRO
    int total=0,j=0;
    char bin1[16]={0};
    strcpy(bin1,Bin1);

    //INVERTE OS VALORES E EM SEGUIDA OS MULTIPLICA LOGO EM SEGUIDA
    for(int i=15; i>0;i--){
        if(bin1[i]=='0'){
            bin1[i]='1';
        }else if(bin1[i]=='1'){
            bin1[i]='0';
        }
        if(bin1[i]=='1'){
            total += pow(2,j);
        }
        j++;
    }

    //VERIFICA SE O PRIMEIRO DIGITO É 1 POR CONTA DO SINAL DE AMPLITUDE E RETORNA O TOTAL POSITIVO OU NEGATIVO
    if(bin1[0]=='0'){
        return -1*total;
    }
    return total;
}

int bin2ToDec(char Bin2[16]){

    //ATRIBUIÇÃO DE VALORES
    int total=0,j=0,k=0;
    char bin2[16]={0};
    strcpy(bin2,Bin2);

    for(int i=15;i>0;i--){
        if(bin2[i]=='1'){
            break;
        }else{
            k++;
        }
    }
    if(k==15){
        return 0;
    }

    if(bin2[15]==48){
    bin2[15]=47;
    }else {
    bin2[15]=48;
    }

    for(int i=15;i>0;i--){

        if (bin2[i]==47){
            bin2[i]=48;
            if (i==1){
                break;
            }
            if(bin2[i-1]==49){
                bin2[i-1]=48;
            }else if(bin2[i-1]==48){
                bin2[i-1]=47;
            }
        }
    }

    //INVERTE OS VALORES PARA ENCONTRAR O BINARIO DE COMPLEMENTO 1
    for(int i=0; i<16;i++){
        if(bin2[i]=='0'){
            bin2[i]='1';
        }else if(bin2[i]=='1'){
            bin2[i]='0';
        }
    }

    //CONVERTE PARA INTEIRO
    for(int i=15;i>=1;i--){
    if(bin2[i]=='1'){
            total += pow(2,j);
        }
        j++;
    }

    //PERCEBE SE O RESULTADO VAI SER POSITIVO OU NEGATIVO
    if(bin2[0]=='1'){
        return -1*total;
    }
    return total;
}
