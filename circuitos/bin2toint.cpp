#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int main(){
    int total=0,j=0;
    char bin2[16]={0};
    scanf("%s", bin2);

    if(bin2[15]=='1'){
        bin2[15]='0';
    }else if(bin2[15]=='0'){
        bin2[15]='1';
        if(bin2[14]=='1'){
            bin2[14]='0';
        }else if(bin2[14]=='0'){
                bin2[14]='1';
                if(bin2[13]=='1'){
                    bin2[13]='0';
                }else if(bin2[13]=='0'){
                    bin2[13]='1';
                    if (bin2[12]=='1'){
                        bin2[12]='0';
                    }else if (bin2[12]=='0'){
                        bin2[12]='1';
                        if (bin2[11]=='1'){
                            bin2[11]='0';
                        }else if (bin2[11]=='0'){
                            bin2[11]='1';
                            if (bin2[10]=='1'){
                                bin2[10]='0';
                            }else if(bin2[10]=='0'){
                                bin2[10]='1';
                                if (bin2[9]=='1'){
                                    bin2[9]='0';
                                }else if(bin2[9]=='0'){
                                    bin2[9]='1';
                                    if (bin2[8]=='1'){
                                        bin2[8]='0';
                                    }else if (bin2[8]=='0'){
                                        bin2[8]='1';
                                        if(bin2[7]=='1'){
                                            bin2[7]='0';
                                        }else if (bin2[7]=='0'){
                                            bin2[7]='1';
                                            if(bin2[6]=='1'){
                                                bin2[6]='0';
                                            }else if(bin2[6]=='0'){
                                                bin2[6]='1';
                                                if (bin2[5]=='1'){
                                                    bin2[5]='0';
                                                }else if (bin2[5]=='0'){
                                                    bin2[5]='1';
                                                    if (bin2[4]=='1'){
                                                        bin2[4]='0';
                                                    }else if(bin2[4]=='0'){
                                                        bin2[4]='1';
                                                        if(bin2[3]=='1'){
                                                            bin2[3]='0';
                                                        }else if(bin2[3]=='0'){
                                                            bin2[3]='1';
                                                            if (bin2[2]=='1'){
                                                                bin2[2]='0';
                                                            }else if (bin2[2]=='0'){
                                                                bin2[2]='1';
                                                                if (bin2[1]=='1'){
                                                                    bin2[1]='0';
                                                                }else if(bin2[1]=='0'){
                                                                    bin2[1]='1';
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
        }
    }
    printf("%s\n", bin2);
    for(int i=0; i<16;i++){
        if(bin2[i]=='0'){
            bin2[i]='1';
        }else if(bin2[i]=='1'){
            bin2[i]='0';
        }
    }
    for(int i=15;i>=1;i--){
    if(bin2[i]=='1'){
            total += pow(2,j);
        }
        j++;
    }

    printf("%s",bin2);

    if(bin2[0]=='1'){
        return -1*total;
    }
    return total;
    system("PAUSE");
}
