#include <stdio.h>

int readLine(char line[], int maxLength);
void printArray(char line[]);
void copyArray(char from[], char to[]);

int main()
{
    int len;
    int longest;
    char lineBuf[100];
    char longestBuf[100];

    while ((len = readLine(lineBuf, 100)) > 0)
    {
        if (len > longest)
        {
            longest = len;
            copyArray(lineBuf, longestBuf);
        }
    }

    printf("longest:");
    printArray(longestBuf);

    return 0;
}

int readLine(char line[], int maxLength)
{
    int character, pos;

    pos = 0;
    character = getchar();

    while (character != EOF && character != '\n')
    {
        line[pos] = character;

        character = getchar();
        pos++;
    }

    if (pos == 0)
    {
        return 0;
    }
    else
    {
        line[++pos] = '\0';
        return pos;
    }
}

void copyArray(char from[], char to[])
{
    int pos = 0;

    while (from[pos] != '\0')
    {
        to[pos] = from[pos];
        pos++;
    }
}

void printArray(char line[])
{

    int pos = 0;

    while (line[pos] != '\0')
    {
        printf("%c", line[pos]);
        pos++;
    }
    printf("\n");
}