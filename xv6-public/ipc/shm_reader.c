#include <sys/ipc.h> //InterProcess Communication
#include <sys/shm.h> //Shared memory
#include <unistd.h>
#include <stdio.h>

int main(){
    int key = 27; //Numero usado para generar el id del bloque de memoria.
    int shmid = shmget(key, 100, IPC_CREAT); //te genera el id
    //Cualquiera de los dos anteriores es suficiente.
    char *word;

    word = (char *)shmat(shmid, NULL, 0); //Hacemos cast en un arreglo de caracteres, 0 es lectura y escritura, si es otro es solo lectura.
    //word = "Hello world"; //remplaza el apuntador.

    printf("Lo que hay en la memoria es: %s\n", word);
    word[0] = '*';
    return 0;
}