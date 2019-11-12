#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void escribir(int temp, char *palabra, int length);

int main(int argc, char **argv){
    char *fileName = argv[1];
    char *patron = argv[2];
    char *nuevo = argv[3];
    char word[100]; //Buffer para guardar las copias
    char c;  //caracter para copiar los caracteres
    int i=0;
    int fd = open(fileName, O_RDONLY); //read(2) - Linux man page
    int temporal = open("temporal.txt", O_WRONLY|O_CREAT, 0666); //creamos el archivo, par asoloe scritura, y si no existe lo crea

    while(read(fd,&c,1)){
        if(c != ' '){
            word[i++]=c;
        }else{
            word[i]='\0';
            i=0;
            if(!strcmp(word, argv[2])){
                //write(temporal, argv[3], strlen(argv[3]));
                //write(temporal, " ", 1); //Le agregamos el espacio
                escribir(temporal, argv[3], strlen(argv[3]));
            }else{
                //write(temporal, word, strlen(word));
                //write(temporal, " ", 1);
                escribir(temporal, word, strlen(word));
            }
        
        }
    }
    word[i]='\0';
    if(!strcmp(word, argv[2])){
        //write(temporal, argv[3], strlen(argv[3]));
        //write(temporal, " ", 1); //Le agregamos el espacio
        escribir(temporal, argv[3], strlen(argv[3]));
    }else{
        //write(temporal, word, strlen(word));
        //write(temporal, " ", 1);
        escribir(temporal, word, strlen(word));
    }
            
    close(fd);
    close(temporal);
    unlink(fileName);
    link("temporal.txt",fileName);
    unlink("temporal.txt");

return 0;
}

void escribir(int temp, char *palabra, int length){
    write(temp, palabra, length);
    write(temp, " ", 1);
}
