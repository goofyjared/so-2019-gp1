#include "stdio.h"

    void printHello(char *str){
        printf("Hola hi %s\n", str);
    }

int main(int argc, char **argv){

   // return 1;
//Hubo un problema cuando no regresa 0, regresa 1
    int i;
    for(i=1; i<argc; i++){
        printHello(argv[i]);
    }

    return 0;
}