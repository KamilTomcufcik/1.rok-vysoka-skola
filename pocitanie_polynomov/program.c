#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    char temp[10];
    double koef[50];
    double vysledok=0, x=0;
    int i=0, pomocna=0;

    //          NACITANIE       X
    fgets(temp, 10, stdin);
    if(temp[0]=='\n'||temp[0]=='\0'){
        printf("Nepodarilo sa nacitat zaklad x\n");
        return 0;
    }
    else{
        x = atof(temp);
        if(x==0 && temp[0]!='0'){
            printf("Nepodarilo sa nacitat zaklad x\n");
            return 0;
        }
    }
    memset(&temp[0], 0, sizeof(temp));

    //          NACITANIE       KOEFICIENTOV
    while(pomocna!=50){
        fgets(temp, 10, stdin);
        if(temp[0]=='\n'||temp[0]=='\0'){
            break;
        }
        koef[pomocna]= atof(temp);
        if(koef[pomocna]==0&&temp[0]!='0'){ 
                printf("Nepodarilo sa nacitat polynom na %i mieste.\n", pomocna+1);
            return 0;
        }
        //printf("chzba %f\n", koef[pomocna]);
        pomocna++;
        memset(&temp[0], 0, sizeof(temp)); 
    }

    //          POCITANIE       VYSLEDKU
    while(pomocna!=0){
        //printf("x%f  koef%f     vz%.2lf\n", x, koef[i], vysledok);
        vysledok+= koef[i]* pow(x, pomocna-1);
        i++;
        pomocna--;
    }
    printf("Vysledok je: %.2lf\n", vysledok);

    return 0;
}