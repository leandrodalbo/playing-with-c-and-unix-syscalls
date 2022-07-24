#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    for (int i = 0; i < argc; i++)
    {
        printf("argument number: %d, --> %s \n", i, argv[i]);
    }
}
