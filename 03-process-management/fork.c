#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>

static void child()
{
    printf("I am child! my pid is %d.\n", getpid());
    exit(EXIT_SUCCESS);
}

static void parent(pid_t pid_c)
{
    printf("I am parent! my pid is %d and the pid of my child is %d.\n", getpid(), pid_c);
    exit(EXIT_SUCCESS);
}

int main(void)
{
    pid_t ret;
    ret = fork();
    if (ret == -1)
    {
        err(EXIT_FAILURE, "fork() failed");
    }
    if (ret == 0)
    {
        //child process came here because fork() returns 0 for child process
        child();
    } 
    else
    {
        //parent process came here because fork() returns the pid of newly created child process(>1)
        parent(ret);
    }

    //should not reach here
    err(EXIT_FAILURE, "should not reach here");
}