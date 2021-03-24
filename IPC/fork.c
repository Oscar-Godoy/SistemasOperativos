#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void signalHandler(int sig){
     wait(NULL);
}

int main(){
            signal(17, signalHandler);
    int pid = fork();
    int pidHijoTermin;
    if(pid == 0){
        //Proceso hijo
        printf("Soy el proceso hijo\n");
    }else{

        printf("Soy el proceso padre y mi hijo es %d\n", pid);
        while(1){
            printf("Trabajando \n");
            sleep(1);
        }
        printf("Mi hijo terminó %d\n", pidHijoTermin);
    }
    printf("Terminamos\n");
    return 0; 
}