#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    int f1, f2, readBytes;
    char buf[BUFSIZ];

    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
    {
        printf("can't open file %s", argv[1]);
    }

    if ((f2 = creat(argv[2], 0666)) == -1)
    {
        printf("can't create file %s", argv[2]);
    }

    while ((readBytes = read(f1, buf, BUFSIZ)) > 0)
    {
        write(f2, buf, readBytes);
    }
}