#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
    char *viejo = argv[1];
    char *nuevo = argv[2];
    int renombrar = link(viejo, nuevo);
    return unlink(viejo);
}