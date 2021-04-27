#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{

    int pp2c[2];

    int pc2p[2];

    pipe(pp2c);
    pipe(pc2p);

    switch(fork()){

        case -1:
            break;

        case 0:
            close(pp2c[1]);
            dup2(pp2c[0],STDIN_FILENO);
            close(pp2c[0]);
            close(pc2p[0]);
            dup2(pc2p[1],STDOUT_FILENO);
            close(pc2p[1]);

            execlp("bc","bc","-l",(char*)NULL);
            break;
        default:

            close(pp2c[0]);
            close(pc2p[1]);


            FILE *out = fdopen(pp2c[1],"w");
            FILE *in = fdopen(pc2p[0],"r");


            char funcion[1024];
            char init[1024];
            char fin[1024];
            char iter[1024];


            while(1){ //WHILE PARA MANDARLE INFO AL HIJO CON PRINTF
                
                scanf("%s",funcion);
                scanf("%s %s %s", init, fin, iter);

                float initInt = atof(init);
                float finInt = atof(fin);
                float iterInt = atof(iter);

                float aumento = (finInt - initInt)/iterInt;
                float punto = initInt;


                for(float i=0; i<iterInt; i++){
                    punto += aumento; 
                    //printf("Evaluando función en el punto %f...\n",punto);
                    fprintf(out,"x=%f\n",punto);
                    fprintf(out,"%s\n",funcion);
                }
                break;
                //fprintf(out,"%s\n",funcion);
            }
            fclose(out);


            while(1){
                float suma = 0;
                char numero[1024]; 
                float iterInt = atof(iter);
                for(float i=1; i<=iterInt;i++){
                    fscanf(in,"%s\n",numero);
                    float num = atof(numero);
                    //printf("Se va a sumar %f\n",num);
                    suma += num;
                }
                suma = suma / (iterInt + 1);
                printf("%f\n",suma);
                break;
            }
            fclose(in);

            wait(NULL);
            break;
    }
}