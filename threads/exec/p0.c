#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{

    int childExecutor = fork();

    if (childExecutor < 0)
    {
        exit(-1);
    }

    if (childExecutor > 0)
    {
        int childStatus = 0;
        pid_t waited = waitpid(childExecutor, &childStatus, 0);

        printf("process %d, waited for %d that finished with status %d \n", getpid(), waited, childStatus);
    }

    if (childExecutor == 0)
    {
        printf("process %d, will run p1.c \n", getpid());
        sleep(2);
        execl("./p1", "a1", "b2", "x8",(void *) NULL);
    }

    exit(0);
}