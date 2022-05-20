#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void porovnavanie(const char zadane[], const char mena[][30], int counter, int *pomocna){
    for(int i=0; i<counter; i++){
        if(strcmp(zadane, mena[i]) == 0){
            *pomocna = 0;
            break;
        }
    }
}

void CMP_sort(char mena[][30], int counter){
    char temp[30];
    
    for(int i=0; i<counter-1; i++){
        for(int j=i+1; j<counter; j++){
            if(strcmp(mena[i], mena[j]) > 0){
                strncpy(temp, mena[i], strlen(mena[i]));
                memset(&mena[i][0], 0, sizeof(mena[i]));
                    
                strncpy(mena[i], mena[j], strlen(mena[j]));
                memset(&mena[j][0], 0, sizeof(mena[j]));

                strncpy(mena[j], temp, strlen(temp));
                memset(&temp[0], 0, sizeof(temp));
            }
        }
    }
}

int main(){
    char mena[60][30];
    char zadane[30];
    int counter=0, pomocna, pocet=0;

    for(int i=0; i<30; i++){
        memset(&mena[i][0], 0, sizeof(mena[i]));
    }

    fgets(zadane, 30, stdin);
    pocet = atoi(zadane);
    if(pocet <= 0){
        puts("Nespravny vstup");
        return 0;
    }

    while(1){
        pomocna = 1;
        
        if(fgets(zadane, 30, stdin) == NULL) break;
        if(counter == 0 && zadane[0] == '\n'){
            puts("Ziadne prihlasky");
            return 0;
        }
        if(zadane[0] == '\n') break;

        if(counter > 0){
            porovnavanie(zadane, mena, counter, &pomocna);
        }
        if(pomocna == 1){
            strncpy(mena[counter], zadane, strlen(zadane));
            counter++;
        }  
    }

    CMP_sort(mena, counter);
    
    for(int i=0; i<counter; i++){
        if(i == 0) puts("Prijati studenti:");
        if(i == pocet) puts("Neprijati studenti:");
        for(int j=0; j<strlen(mena[i]); j++){
            printf("%c", mena[i][j]);
        }
    }

    return 0;
}