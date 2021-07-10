#include <unistd.h>
#include <stdio.h>
#include <err.h>
#include <stdlib.h>

static void child()
{
    char* args[] = {"/bin/echo", "hello", NULL};
    printf("I am child! my pid is %d!\n", getpid());
    fflush(stdout);
    execve("/bin/echo", args, NULL);
    err(EXIT_FAILURE, "exec() failed");
}

static void parent(pid_t pid_c)
{
    printf("I am parent! my pid is %d and the pid of my child is %d!", getpid(), pid_c);
    exit(EXIT_SUCCESS);
}

int main(void)
{
    pid_t ret = fork();
    if (ret == -1)
    {
        err(EXIT_FAILURE, "fork() failed!");
    }
    if (ret == 0)
    {
        child();
    }
    else
    {
        parent(ret);
    }

    err(EXIT_FAILURE, "should not reach here!");
    
}
