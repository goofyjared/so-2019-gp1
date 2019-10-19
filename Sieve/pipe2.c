#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//PRIMES JUAN JARED ABUD TRIANA A01228819
int main() {
  int num = 0; //Variable global donde guardaremos cada numero escaneado
  int anterior = 0; //variable global donde guardaremos el primer numero escaneado
  int repeticion = 1; //Variable que nos indica la primera iteración para guardar el primer numero

  while(1){
    if(repeticion){
        scanf("%d\n",&num); //Escaneamos el primer numero, en el primer caso será el 2
        anterior = num; //Guardamos para siempre este numero
        fprintf(stderr,"primo %d\n", num); //Lo imprimimos como nuestro primer numero primo, tiene que ser como stderr para que no lo detecte como input el sistema
        repeticion=0; //Ya salimos de la primera repetición
    }else{
        scanf("%d\n",&num); //Scaneamos los numeros que faltan
        if(num%anterior!=0){ //Si no son multiplis del guardado, o sea, no son multiplos de 2, se imprimen como printf
            printf("%d\n",num);
        }
    }
    if(num == -1){
      break;
    }

  }

  fprintf(stderr, "completado\n");
}