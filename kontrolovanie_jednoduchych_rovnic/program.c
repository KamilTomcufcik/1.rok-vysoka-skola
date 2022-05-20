#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float round2(float x) {
    return (float) (floor(x * 100.0f + 0.5f) / 100.0f);
}

void porovnavanie(float a, float cislo){
    if(round2(a) == cislo) printf("OK\n");
    else printf("ZLE\n");
}

int main(){
    char *ls, *ps;
    char zadane[150];
    float cislo[4];
    char *kopia;
    char znamienko;
    int pomocna;
    float a=0;
    int counter1, counter2;

    while(1){
        pomocna=0;
        counter1=0;
        counter2=0;

        if(fgets(zadane, 150, stdin) == NULL) break;
        if(zadane[0] == '\n') break;
        for(int i=0; i<strlen(zadane)-1; i++){
            if(zadane[i] > 61 || zadane[i] < 32 || (zadane[i] > 32 && zadane[i] < 42) || (zadane[i] > 57 && zadane[i] < 61) || zadane[i] == 44){
                printf("CHYBA\n");
                pomocna=1;
                break;
            }
        }

        if(pomocna==0){
            kopia = strdup(zadane);
            ls = strtok(zadane, "=");
            ps = strtok(NULL, "\n");
            if(strchr(ls, '+') == NULL && strchr(ls, '*') == NULL && strchr(ls, '-') == NULL && strchr(ls, '/') == NULL){
                pomocna=1;
                printf("CHYBA\n");
            }

            if(pomocna==0){
                cislo[2] = atof(ps);
                ls = strtok(ls, "+*-/");
                znamienko = kopia[strlen(ls)];
                free(kopia);
                for(int i=0; i<2; i++){
                    if(ls!=NULL){
                        cislo[i] = atof(ls); 
                    }
                    if(cislo[i] == 0){
                        for(int j=0; j<strlen(ls); j++){
                            if(ls[j] == ' ') counter1++;
                            else break;    
                        }
                        if(ls[counter1] != '0' && pomocna == 0){                    
                            pomocna = 1;
                            printf("CHYBA\n");
                        }
                        counter1 = 0;
                    }
                    ls = strtok(NULL, "+*-/");
                }
                for(int i=0; i<strlen(ps); i++){
                    if(ps[i] == ' ') counter2++; 
                    else break; 
                }
                if(cislo[2] == 0){
                    if(ps[counter2] != '0' && pomocna == 0){
                        printf("CHYBA\n");
                        pomocna = 1;
                    }   
                }
            }
        }

        if(pomocna==0){
            if(znamienko == '+' ){
                a = cislo[0] + cislo[1];
                porovnavanie(a, cislo[2]);
            }
            else if(znamienko == '-' ){
                a = cislo[0] - cislo[1];
                porovnavanie(a, cislo[2]);
            }
            else if(znamienko == '*' ){
                a = cislo[0] * cislo[1];
                porovnavanie(a, cislo[2]);
            }
            else if(znamienko == '/' ){
                a = cislo[0] / cislo[1];
                porovnavanie(a, cislo[2]);
            }
        }
    }
    
    return 0;
}