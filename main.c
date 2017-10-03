#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pid_t child[10];
    int i;

    printf("main: pid %d, ppid %d\n", getpid(), getppid());
    for(i=0; i<10; i++)
    {
    child[i] = fork();
    if (child[i] == 0)
    {printf("child: created with pid %d, ppid %d\n", getpid(), getppid()); exit(EXIT_SUCCESS);}
    else if (child[i] == -1)
         { perror("problem creating a child");return -1;}
    else
        {
        printf("main: created child %d\n", child[i]);
        }
    }
    wait();
    printf("Hello World!\n");
    return EXIT_SUCCESS;
}
