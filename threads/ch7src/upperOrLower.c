#include <stdio.h>
#include <ctype.h>
#include <string.h>

//echo longword | ./upperOrLower -u  (exercise 7-1)
int main(int argc, char *argv[])
{
    int isUpper = 0;

    if (argc > 1)
    {
        if (strcmp(argv[1], "-u") == 0)
        {
            isUpper = 2;
        }
        else
        {
            isUpper = 0;
        }
    }

    int c;
    while ((c = getchar()) != EOF)
    {
        putchar((isUpper) ? toupper(c) : tolower(c));
    }

    return 0;
}