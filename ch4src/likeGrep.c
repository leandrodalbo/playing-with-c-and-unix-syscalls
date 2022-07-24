#include <stdio.h>

const int MAX_LINES = 3;
const int LINE_LENGTH = 6;

void readLine(char buf[], int maxLength);
int containsPattern(char line[], char pattern[]);

int main()
{

    char buf[MAX_LINES][LINE_LENGTH];
    char patternBuf[LINE_LENGTH];

    printf("load lines:\n");
    for (int i = 0; i < MAX_LINES; i++)
    {
        readLine(buf[i], LINE_LENGTH);
    }

    printf("load pattern :\n");
    readLine(patternBuf, LINE_LENGTH);

    for (int i = 0; i < MAX_LINES; i++)
    {
        int patternIdex = containsPattern(buf[i], patternBuf);

        if (patternIdex != -1)
        {
            for (int j = 0; j < LINE_LENGTH; j++)
            {
                printf("%c", buf[i][j]);
            }
            printf(" on index: %d\n", patternIdex);
        }
    }

    return 0;
}

int containsPattern(char line[], char pattern[])
{
    int i = 0;
    while (line[i] != '\0')
    {
        int aux = i;
        int j = 0;

        while (pattern[j] == line[aux] && pattern[j] != '\0')
        {
            j++;
            aux++;
        }

        if (pattern[j] == '\0')
        {
            return i;
        }
        i++;
    }

    return -1;
}

void readLine(char linebuf[], int lineLength)
{
    int c, i;

    i = 0;
    while (i < lineLength && (c = getchar()) != EOF && c != '\n')
    {
        linebuf[i] = c;
        i++;
    }

    if (i >= lineLength)
    {
        printf("invalid line!!!");
    }

    linebuf[i] = '\0';
}