#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int main(){
    int total=0,j=0;
    char bin1[16]={0};
    scanf("%s", bin1);

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

    if(bin1[0]=='1'){
        return -1*total;
    }
    return total;

}

