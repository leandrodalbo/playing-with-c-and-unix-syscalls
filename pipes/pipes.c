#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1

void pipeReader(int fd);
void pipeWriter(int fd, int arg, char *argv[]);

int main(int argc, char *argv[])
{

    int fds[2];
    int openPipe = pipe(fds);

    if (openPipe == -1)
    {
        exit(EXIT_FAILURE);
    }

    switch (fork())
    {
    case -1:
        exit(EXIT_FAILURE);
        break;
    case 0:
        close(fds[1]);
        pipeReader(fds[0]);
        close(fds[0]);
        break;

    default:
        close(fds[0]);
        pipeWriter(fds[1], argc, argv);
        close(fds[1]);

        sleep(2);
        wait(NULL);
        break;
    }

    exit(EXIT_SUCCESS);
}

void pipeReader(int fd)
{
    char buf[BUFFER_SIZE] = {};

    read(fd, buf, BUFFER_SIZE);

    while (strlen(buf) > 0)
    {
        printf("pipe data ->: %s \n", buf);
        strcpy(buf, "");
        read(fd, buf, BUFFER_SIZE);
    }
}

void pipeWriter(int fd, int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {

        write(fd, argv[i], strlen(argv[i]));
    }
}