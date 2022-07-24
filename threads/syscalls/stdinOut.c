#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
 ./stdinOut < stdinOut.c
 
*/
int main(int argc, char const *argv[])
{
    char buf[BUFSIZ];
    int readBytes;

    while ((readBytes = read(0, buf, BUFSIZ)) > 0)
    {
        write(1, buf, BUFSIZ);
    }

    exit(0);
}
