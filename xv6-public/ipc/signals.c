#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int forever = 1;

void signalHandler(int signal){
    printf("Received signal: %d\n", signal);
    forever=0;
}

int main(){
    int pid; //vale algo al principio
    signal(10, signalHandler); //Recibe como parametros una señal y la funcion a ejecutar
    pid = fork(); //fork es una llamada al sistema, vale algo despues

    if (pid==0){
        //soy el hijo
        printf("Soy el proceso hijo\n");
        //Código que quiero que haga el hijo
       while(forever){}
       printf("Saliendo del cliclo infinito\n");
    } else{
        printf("Soy el proceso padre y mi hijo es: %d\n", pid);
        sleep(5);
        kill(pid, 10);
        //Código del padre
        for(;;){}
    }
}