#include <sys/ipc.h> //InterProcess Communication
#include <sys/shm.h> //Shared memory
#include <unistd.h>
#include <stdio.h>

int main(){
    int key = 27; //Numero usado para generar el id del bloque de memoria.
    int shmid = shmget(key, 100, IPC_CREAT); //te genera el id
    //Cualquiera de los dos anteriores es suficiente.
    char *word;

    word = (char *)shmat(shmid, NULL, 0 |0666); //Hacemos cast en un arreglo de caracteres, 0 es lectura y escritura, si es otro es solo lectura.
    //word = "Hello world"; //remplaza el apuntador.
    sprintf(word, "Hello world"); //word[0]=H, word[1]=e, guarda caracteres en casillas, lo trata como si fuera un arreglo

    while(word[0 == 'H']){
        sleep(1);
    }

    printf("Sali del ciclo: %s", word);
    return 0;

}