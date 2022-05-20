#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void porovnavanie(const char zadane[], const char pole[][30], int *pomocna, int counter, int *index){
    for(int i=0; i<counter; i++){
        for(int j=0; j<strlen(zadane); j++){
            if(zadane[j] != pole[i][j]){
                *pomocna = 1;
                break;
            }
            else if(*pomocna != 0){
                *pomocna = 0;
                *index = i;
            }
        }
        if(*pomocna == 0) break;
    }
}

void body_sort(int *body, char pole[][30], int counter){
    int a=0, max_index=0, temp1=0;
    char temp2[50];
    memset(&temp2[0], 0, sizeof(temp2));

    while(a < counter){
        max_index = a;

        for(int i=a; i<counter; i++){
            if(body[i] > body[max_index]){
                max_index = i;
            }
        }

        temp1 = body[a];
        body[a] = body[max_index];
        body[max_index] = temp1;
        
        strncpy(temp2, pole[a], strlen(pole[a]));
        memset(&pole[a][0], 0, sizeof(pole[a]));
        
        strncpy(pole[a], pole[max_index], strlen(pole[max_index]));
        memset(&pole[max_index][0], 0, sizeof(pole[max_index]));

        strncpy(pole[max_index], temp2, strlen(temp2));
        memset(&temp2[0], 0, sizeof(temp2));

        a++;
    }
}

void lex_sort(char pole[][30], int pocet, int index){
    int  b=0, max_index=0, j=0;
    char temp2[50];
    memset(&temp2[0], 0, sizeof(temp2));

    while(b < pocet){
        max_index = index + b; 
           
        for(j=index+b; j<(index+pocet); j++){
            if(pole[j][0] < pole[max_index][0]){
                max_index = j;
            }  
        }
        //vymena
        strncpy(temp2, pole[index+b], strlen(pole[index+b]));
        memset(&pole[index+b][0], 0, sizeof(pole[index+b]));
            
        strncpy(pole[index+b], pole[max_index], strlen(pole[max_index]));
        memset(&pole[max_index][0], 0, sizeof(pole[max_index]));

        strncpy(pole[max_index], temp2, strlen(temp2));
        memset(&temp2[0], 0, sizeof(temp2));
         
        b++;  
    }
}

int main(){
    char meno[10][30], zadane[30];
    char abeceda[] = "abcdefghijklmopqrstuvwxyz";
    char *temp1, *temp2;
    int body[10];
    int pomocna, counter = 0, index = 0;
    
    for(int i=0; i<10; i++){
        memset(&meno[i][0], 0, sizeof(meno[i]));
    }

    while(1){
        pomocna = 1;

        if(fgets(zadane, 30, stdin) == NULL){
            printf("Nepodarilo nacitat nic\n");
            break;
        } 
        if(zadane[0] == '\n') break;

        temp1 = strtok(zadane, " ");
        temp2 = strtok(NULL, "\n");

        if(strpbrk(temp1, abeceda) != NULL && counter == 0){
            printf("Nepodarilo nacitat nic\n");
            break;
        } 
        if(strpbrk(temp1, abeceda)!=NULL) break;

        if(counter > 0){
            porovnavanie(temp2, meno, &pomocna, counter, &index);
        }  
        if(pomocna == 1){
            body[counter] = atoi(temp1);
            strncpy(meno[counter], temp2, strlen(temp2));
            counter++;
        }
        else{
            body[index] += atoi(temp1);
        }
    }

    body_sort(body, meno, counter);

    int neviem, pocet=1;
    neviem = body[0];
    for(int i=1; i<counter; i++){
        if(body[i] == neviem){
            index = i-1;
            for(int j=i; j<counter; j++){
                if(body[j] == neviem) pocet++;
                else {
                    i = j-1;
                    break;
                }
                if((j+1) == counter){
                    i = j;
                    break;
                }
            }
            lex_sort(meno, pocet, index);
            pocet = 1;
        }
        else neviem = body[i];
    }

    if(counter != 0){
        printf("Vysledky:");
        for(int i=0; i<counter; i++){
            printf("\n%i ", body[i]);
            for(int j=0; j<strlen(meno[i]); j++){
                printf("%c", meno[i][j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}