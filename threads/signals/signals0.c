#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

static void signalHandler(int signalNumber)
{

    printf("signal received: %d \n", signalNumber);

    if (signalNumber == SIGINT)
    {
        exit(EXIT_SUCCESS);
    }
}

int main()
{
    if (signal(SIGINT, signalHandler) == SIG_ERR)
    {
        exit(EXIT_FAILURE);
    }

    if (signal(SIGALRM, signalHandler) == SIG_ERR)
    {
        exit(EXIT_FAILURE);
    }

    alarm(1);

    while (1);
}