#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char *filename = argv[1];
  char *atributo = argv[2];
  char *dato = argv[3];
  FILE *forigen;
  forigen = fopen(filename,"rb");
  STUDENT newstudent;
  while(fread(&newstudent, sizeof(newstudent), 1 ,forigen)){

    fread(&newstudent,sizeof(newstudent),1,forigen);
    if(atributo == "nombre" && strcmp(newstudent.name,dato) == 0){
        strcpy(newstudent.name, dato):
        fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
        fwrite(&newstudent, sizeof(newstudent), 1 , forigen);
    }else if(atributo == "apellido" && strcmp(newstudent.lastname,dato) == 0){
        strcpy(newstudent.lastname, dato):
        fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
        fwrite(&newstudent, sizeof(newstudent), 1 , forigen);
    }else if(atributo == "id" && newstudent.id == atoi(dato)){
        newstudent.id = atoi(dato):
        fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
        fwrite(&newstudent, sizeof(newstudent), 1 , forigen);
    }else if(atributo == "semestre" && newstudent.semestre == atoi(dato)){
        newstudent.semestre = atoi(dato):
        fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
        fwrite(&newstudent, sizeof(newstudent), 1 , forigen);
  }
  fclose(forigen);
}