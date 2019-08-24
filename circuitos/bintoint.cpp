#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int main(){
    int total=0,aux,j=0;
    char bin[16]={0};
    scanf("%s", bin);

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

