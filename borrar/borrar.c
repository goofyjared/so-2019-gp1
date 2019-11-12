#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
    char *archivo = argv[1];
    return unlink(archivo);
}