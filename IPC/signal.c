#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int varGlobal = 0;

void signalHandler(int sig){
	printf("Recibi segnal %d\n", sig);
	varGlobal = 1;
}

int main(){
	signal(2,signalHandler);
	while(varGlobal!=1){
		printf("Trabajando\n");
		sleep(1);
	}
	printf("Ya voy a terminar");
	return 0;
}