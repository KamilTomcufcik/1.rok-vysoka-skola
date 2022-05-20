#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//gcc -g -Wall program.c -o program -lm

int main(){
    char datum[15];
    char *temp;
    long int date[3];
    int mesiac=0, rok=0;
    int denTemp=0;
    int pomocna=0;
    //      ROK 1 JE PRIESTUPTNZ CI JAK SA VOLA
    //      ROK 0 KLASIK
    //      MESIAC 0    31 DNI
    //      MESIAC 1    30 DNI
    //      MESIAC 2    FEBRUAR

    while(1){
        pomocna=0;
        fgets(datum, 15, stdin);
        if(datum[0]=='\n'){
            break;
        }
        temp = strtok(datum, ".");
        for(int i=0; i<3; i++){
            if(temp!=NULL){
               date[i] = atol(temp); 
            }
            temp = strtok(NULL, ".");
        }
        if(date[2]%4==0){
            rok=1;
        }
        else{
            rok=0;
        }
        if(date[1]==1 || date[1]==3 || date[1]==5 || date[1]==7 || date[1]==8 || date[1]==10 || date[1]==12){
            mesiac=0;
        }
        else if(date[1]==4 || date[1]==6 || date[1]==9 || date[1]==11){
            mesiac=1;
        }
        else{
            mesiac=2;
        }
        if( (mesiac==0 && date[0]>31) || (mesiac==1 && date[0]>30) || (mesiac==2 && rok==0 && date[0]>28) || (mesiac==2 && rok==1 && date[0]>29) || date[0]<1 || date[1]>12 || date[1]<1 || date[2]>2100 || date[2]<1900){
            puts("Neplatny datum.");
            pomocna=1;
        }
        if(pomocna==0){
            denTemp=date[0]+7;
            if(mesiac==2){
                if(rok==0){
                    if(denTemp>28){
                        date[0]=denTemp-28;
                        date[1]++;
                        printf("%li.%li.%li\n\n", date[0], date[1], date[2]);
                    }
                    else{
                        printf("%i.%li.%li\n\n", denTemp, date[1], date[2]);
                    }
                }
                if(rok==1){
                    if(denTemp>29){
                        date[0]=denTemp-29;
                        date[1]++;
                        printf("%li.%li.%li\n\n", date[0], date[1], date[2]);
                    }
                    else{
                        printf("%i.%li.%li\n\n", denTemp, date[1], date[2]);
                    }
                }
            }
            if(mesiac==1){
                if(denTemp>30){
                    date[0]=denTemp-30;
                    date[1]++;
                    printf("%li.%li.%li\n\n", date[0], date[1], date[2]);
                }
                else{
                    printf("%i.%li.%li\n\n", denTemp, date[1], date[2]);
                }
            }
            if(mesiac==0){
                if(denTemp>31){
                    date[0]=denTemp-31;
                    if(date[1]==12){
                        date[1]=1;
                        date[2]++;
                    }
                    else{
                        date[1]++;
                    }
                    printf("%li.%li.%li\n\n", date[0], date[1], date[2]);
                }
                else{
                    printf("%i.%li.%li\n\n", denTemp, date[1], date[2]);
                }
            }
        }
    }
    return 0;
}