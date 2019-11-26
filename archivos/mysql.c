#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


typedef struct s{
   char firstName[20];
   char lastName[20];
   int studentId;
   char semester;
} Student;

int writeStudent(int argc, char **argv){
    char *fileName = argv[1];
    int fd2 = open(fileName, O_WRONLY|O_CREAT, 0666); //Abrimos archivo
    for(int i=0;i<10;i++){
        Student myStudent;
        myStudent.studentId = (i+1)*10;
        myStudent.semester = (i+1);
        sprintf(myStudent.firstName, "juanito_%d", i);
        sprintf(myStudent.lastName, "perez_%d", i);
        write(fd2, &myStudent, sizeof(myStudent)); //a cualquier variable ponemos el & para poner su direccion de memoria
    }
    close(fd2); //Cerramos archivo
    return 0;
}

int readStudent(int argc, char **argv){
    char *fileName = argv[1];
    int fd2 = open(fileName, O_RDONLY); //Abrimos archivo
    Student myStudent;
    while(read(fd2, &myStudent, sizeof(myStudent))){
        printf("%s %s : %d: %d\n",myStudent.firstName,myStudent.lastName,myStudent.studentId,myStudent.semester);
    }
    close(fd2);
    return 0;
}

int main(int argc, char **argv){
    char *fileName = argv[1];
    char *lastName = argv[2];
    char *newLastName = argv[3];
    int recordPos = -1; //Inicializamos variable como -1 indicando que no la encontró.
    int i = -1;
    int fd2 = open(fileName, O_RDONLY); //Abrimos archivo
    Student myStudent;
    while(read(fd2, &myStudent, sizeof(myStudent))){
        i++;
        if(!strcmp(myStudent.lastName, lastName)){
            recordPos = i;
            break;
        }
    }
    close(fd2);
    if(recordPos != -1){
        printf("El record existe en la posicion %d\n", recordPos);
        char lastNameBuf[sizeof(myStudent.lastName)];
        strncpy(lastNameBuf, newLastName, sizeof(myStudent.lastName));
        fd2 = open(fileName, O_WRONLY); //Abrimos archivo
        lseek(fd2, recordPos*sizeof(myStudent) + sizeof(myStudent.firstName), SEEK_SET);//lseek nos sirve para recorrer una posicion en memoria.
        write(fd2, lastNameBuf, sizeof(myStudent.lastName));
        close(fd2);
    } else{
        printf("El record no existe\n");
    }

    return 0;
}