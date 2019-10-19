#include "types.h"
#include "stat.h"
#include "user.h"
//SLEEP JUAN JARED ABUD TRIANA A01228819
int main(int argc, char *argv[]) {
	if (argc < 2){
		printf(2, "Error: no hay parametro\n");
		exit();
	}
	int tiempo = atoi(argv[1]);
	if (tiempo > 0){
		sleep(tiempo);
	} else {
		printf(2, "Error: parametro incorrecto -> %s\n", argv[1]);
	}
	exit();
}