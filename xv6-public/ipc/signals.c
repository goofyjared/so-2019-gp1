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
    pid = fork(); //fork es una llamada al sistema, clonamos el proceso, el padre tiene un id, y el id del hijo ahora es 0

    if (pid==0){ //Este es el codigo del hijo
        //soy el hijo
        printf("Soy el proceso hijo\n");
        //Código que quiero que haga el hijo
       while(forever){} //Se queda ciclado hasta que se llama a la interrupción
       printf("Saliendo del cliclo infinito\n");
    } else{
        printf("Soy el proceso padre y mi hijo es: %d\n", pid); //Es el proceso padre
        sleep(5);
        kill(pid, 10);
        //Código del padre
        for(;;){}
    }
}