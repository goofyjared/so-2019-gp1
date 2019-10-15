
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define NUM_FILOS 5
pthread_mutex_t forks[NUM_FILOS];

void actions(){
    sleep(1 + rand()%5); //va a dormir de 1 a segundos en total
}

void * life(void *ptId){
    long tid;
    tid = (long)ptId;
    srand(time(NULL)+tid); //inicializa la semilla, time va a regresar el tiempo del reloj
    while(1){
        printf("Voy a pensar un rato %ld\n", tid); //ld por que es largo
        actions();
        printf("Tengo hambre %ld\n", tid); //ld por que es largo
        //pensar
        if(tid%2==0){ //Si es par
            pthread_mutex_lock(&forks[tid]);//le mandamos la direccion ara que modifique
            printf("Ya tengo el tenedor derecho %ld\n", tid); //ld por que es larg
            pthread_mutex_lock(&forks[(tid+1)%NUM_FILOS]);
            printf("Ya tengo el tenedor izquierdo %ld\n", tid); //ld por que es larg
            printf("Ha comer %ld\n", tid); //ld por que es larg
            actions(); //comer
            printf("Regresando tenedores  %ld\n", tid); //ld por que es larg
            pthread_mutex_unlock(&forks[tid]);//le mandamos la direccion ara que modifique
            pthread_mutex_unlock(&forks[(tid+1)%NUM_FILOS]);
        }else{
            pthread_mutex_lock(&forks[(tid+1)%NUM_FILOS]);
            printf("Ya tengo el tenedor izquierdo %ld\n", tid); //ld por que es larg
            pthread_mutex_lock(&forks[tid]);//le mandamos la direccion ara que modifique
            printf("Ya tengo el tenedor derecho %ld\n", tid); //ld por que es larg
            printf("Ha comer %ld\n", tid); //ld por que es larg
            actions();//comer
            printf("Regresando tenedores  %ld\n", tid); //ld por que es larg
            pthread_mutex_unlock(&forks[tid]);//le mandamos la direccion ara que modifique
            pthread_mutex_unlock(&forks[(tid+1)%NUM_FILOS]);
        }
    }
}

int main(){
   pthread_t threads[NUM_FILOS];
   int rc;
   long t;
   for(t=0;t<NUM_FILOS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, life, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
    }
    pthread_exit(NULL);
}


