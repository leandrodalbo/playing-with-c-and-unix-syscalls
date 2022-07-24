#include <stdio.h>

void readInput(char buf[], int max)
{
    int c, i;

    i = 0;

    while (i < max && (c = getchar()) != EOF && c != '\n')
    {
        buf[i] = c;
        i++;
    }

    if (i >= max)
    {
        printf("invalid input!!!");
    }

    buf[i] = '\0';
}