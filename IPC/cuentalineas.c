#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int main(){

    char caracter;
    int cont = 0; 
    while(read(0,&caracter,1)){
        if(caracter == '\n'){
            cont++;
        }
    }
    printf("%d líneas.\n", cont);
    return 0;
}