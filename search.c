#include "student.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char *filename = argv[1];
  char *atributo = argv[2];
  char *dato = argv[3];
  FILE *forigen;
  forigen = fopen(filename,"rb");
  for (; ; ) {
    STUDENT newstudent;
    
    fread(&newstudent,sizeof(newstudent),1,forigen);
    if(atributo == "nombre" && strcmp(newstudent.name,dato) == 0){
        printf("%s %s %d %d \n", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
        break;
    }else if(atributo == "apellido" && strcmp(newstudent.lastname,dato) == 0){
        printf("%s %s %d %d \n", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
        break;
    }else if(atributo == "id" && newstudent.id == atoi(dato)){
        printf("%s %s %d %d \n", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
        break;
    }else if(atributo == "semestre" && newstudent.semestre == atoi(dato)){
        printf("%s %s %d %d \n", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
        break;
    }else{
        //printf("Error. \n");
        //break;
    }
    // YA LO HABIA SUBIDO ANTES; NOMAS ACTUALIZO CON ESTE COMENTARIO PARA QUE APAREZCA EN EL COMMIT

  }
  fclose(forigen);
}