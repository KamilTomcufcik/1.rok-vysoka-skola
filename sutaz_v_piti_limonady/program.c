#include <stdlib.h>
#include <stdio.h>

int main(){
    int array[100];
    int i=0, max=0, pomocna=0; 
    while(i!=100){
        int r = scanf("%i",&array[i]);
        if (r == 1){
            if(array[i]<0){
                break;
            }
            i++;
            pomocna++;
        }
        else {
            break; 
        }  
    }
    //printf("\n");
    if(pomocna==0){
        printf("Chyba: Málo platných hodnôt.\n");
    }
    for(i=0; i<pomocna; i++){
        printf("Súťažiaci č. %d vypil %d pohárov.\n", i+1, array[i]);
    }
    for(i=0; i<pomocna; i++){
        if(max<array[i])
        max=array[i];
    }
    for(i=0; i<pomocna; i++){
        if(max==array[i])
        printf("Výherca je súťažiaci %d ktorý vypil %d pohárov.\n",i+1,array[i]);
    }
    
    return 0;
}