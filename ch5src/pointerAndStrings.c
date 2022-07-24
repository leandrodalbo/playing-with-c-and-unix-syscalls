#include <stdio.h>
#include <stdlib.h>

void strCp(char *s, char *t);
int strCmp(char *s, char *t);
int strSize(char *s);

int main()
{

    char *aPointer = "very long message!";
    char *bPointer = malloc(20);

    strCp(aPointer, bPointer);

    printf("%s \n", bPointer);
    printf("is a == b %d \n", strCmp(aPointer, bPointer));
    printf("a size %d \n", strSize(aPointer));

    free(bPointer);

    return 0;
}

int strSize(char *s)
{
    int size = 0;

    while (*s != '\0')
    {
        *s++;
        size++;
    }

    return size;
}

int strCmp(char *s, char *t)
{
    while (*s != '\0' && *t != '\0')
    {
        if (*s != *t)
        {
            return 0;
        }
        s++;
        t++;
    }

    if (*s != *t)
    {
        return 0;
    }

    return 1;
}

void strCp(char *s, char *t)
{
    *t = *s;

    while ((*s) != '\0')
    {
        *t = *s;
        t++;
        s++;
    }
}
