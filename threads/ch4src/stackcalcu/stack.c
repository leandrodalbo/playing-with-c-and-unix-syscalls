#include <stdio.h>

char values[3];

void push(int elem)
{

    for (int i = 1; i >= 0; i--)
    {
        values[i + 1] = values[i];
    }

    values[0] = elem;
}

int pop()
{
    int elem = values[0];
    for (int i = 0; i < 2; i++)
    {
        values[i] = values[i + 1];
        values[i + 1] = '\0';
    }

    return elem;
}

void print()
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d,", values[i]);
    }
    printf("\n");
}