#include<unistd.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    printf("nik mok\n");
    int pid = fork();
    int status;
    if(!pid)
    {
        char *argv[3] = {"ls", "-l", NULL};
        execv("/bin/ls", argv);
    }
    else
    {
    //wait(&status);
    printf("kjkfskjfskjfskjfskjfskjfs");
}}
