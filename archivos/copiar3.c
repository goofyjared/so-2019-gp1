#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv){
    char *file1 = argv[1];
    char *file2 = argv[2];
    char *pwd = getcwd(NULL,0);
    char path1[strlen(file1)+strlen(pwd)+2];
    char path2[strlen(file2)+strlen(pwd)+2];
    printf("size path1 %lu\n", strlen(path1));
    sprintf(path1,"%s/%s", pwd, file1);
    sprintf(path2,"%s/%s", pwd, file2);
    printf("pwd %s\n", pwd);

    printf("pwd %s\n", path1);
    printf("pwd %s\n", path2);

    int fd1 = open(path1, O_RDONLY);
    int fd2 = open(path2, O_WRONLY|O_CREAT);

    char buffer[100];
    while(read(fd1,buffer,100)){
        write(fd2, buffer, 100);
    }
    close(fd1);
    close(fd2);


}le(read(fd1,buffer,100)){
        w