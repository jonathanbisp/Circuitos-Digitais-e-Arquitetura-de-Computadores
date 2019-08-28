#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float pivo;
    char bits16[16];

    cin>>pivo;

    for(int i=0;i<16;i++){
        pivo*=2;

        if(pivo>=1){
            bits16[i]='1';
            pivo--;
        }else{
            bits16[i]='0';
        }


    }
    cout<<"Seu numero em binario eh:0.";
    for(int i=0; i<16;i++){
        cout<<bits16[i];
    }
    pivo=0;
    for(int i=0;i<16;i++){
        if (bits16[i]=='1'){
            pivo+= pow(2,-(i+1));
        }
    }
    cout<<endl<<"Seu numero de volta com 16bits eh:"<<pivo;

    return 0;
}
