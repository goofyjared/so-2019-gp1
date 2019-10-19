#include <stdio.h>
#include <stdlib.h>

int main() {
  fprintf(stderr, "pipe 1 sending numbers 2 to 100 to pipe 2\n"); //Vamos a empezar desde el 2, así como s emuestra en el dibujo del proyecto, ya que todos son multiplos de 1
  for (int i = 2; i <= 100; i++) {
    printf("%d\n", i);
  }
  fprintf(stderr, "sending end\n");
  printf("%d\n",-1);
}