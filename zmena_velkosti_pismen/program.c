#include <stdio.h>
#include <stdlib.h>

int main(){
    int pomocna = 0;
    int c = 0;
    while(EOF){
        c = getchar();
        if(c>=65 && c<=90){
            c=c+32;
        }
        else if(c>=97 && c<=122){
            c=c-32;
        }
        else if(c=='\n'){
            pomocna++;
        }
        else if(c==EOF){
            break;
        }
        printf("%c", c);
    }

    printf("\nPočet riadkov: %d\n", pomocna);

    return 0;
}