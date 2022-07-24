#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 50

void reader(int fd);
void writer(int fd);

int main(int argc, char *argv[])
{

    char *fifoPath = "/tmp/readWriteFifo";

    mkfifo(fifoPath, 0660);
    int fd = open(fifoPath, O_RDWR);

    switch (fork())
    {
    case -1:
        exit(EXIT_FAILURE);
        break;
    case 0:
        writer(fd);
        break;

    default:
        reader(fd);
        wait(NULL);
        break;
    }

    close(fd);
    printf("GOOD BYE...");
    exit(EXIT_SUCCESS);
}

void reader(int fd)
{
    char buf[BUFFER_SIZE] = {};

    while (1)
    {
        sleep(1);
        read(fd, buf, BUFFER_SIZE);
        printf("new value read: %s \n", buf);
    }
}

void writer(int fd)
{
    char buf[BUFFER_SIZE] = {};

    while (1)
    {
        sleep(2);
        printf("enter new value...\n");
        fgets(buf, BUFFER_SIZE, stdin);
        write(fd, buf, strlen(buf));
        strcpy(buf, "");
    }
}
