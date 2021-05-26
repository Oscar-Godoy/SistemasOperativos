#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *filenameorigen = argv[1];
    char *filenamedestino = argv[2];
    FILE *forigen;
    FILE *fdestino;
    forigen = fopen(filenameorigen,"rb");
    fdestino = fopen(filenamedestino, "wb");
    char *linea = ".";
    while(linea != NULL){
        //Asume que las líneas son de 256 bits
        fread(&linea, 256, 1, forigen);
        if(strcmp(linea, "hola") != 0){
            fwrite(&linea, 256, 1, fdestino);
        }
    }
    fclose(forigen);
    fclose(fdestino);
}