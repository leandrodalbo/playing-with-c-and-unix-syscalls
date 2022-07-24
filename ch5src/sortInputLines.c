#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readLines(int maxLines, char *linesStorage[]);
void printLines(int totalLines, char *linesStorage[]);
void initLinesStorage(int maxLines, char *linesStorage[]);
void sort(char *list[], int firstIndex, int lastIndex, int (*comp)(char *s1, char *s2));
void swap(char *list[], int a, int b, int pivote);

int defaultCmp(char *s1, char *s2);
int reverseCmp(char *s1, char *s2);

int main(int argc, char *argv[])
{
    int const MAXLINES = 10;
    char *lines[MAXLINES];
    int totalLines = 0;
    int isReverse = 0;

    if (argc > 1 && (strcmp(argv[1], "-r") == 0))
    {
        isReverse = 1;
    }

    if ((totalLines = readLines(MAXLINES, lines)) >= 0)
    {
        sort(lines, 0, totalLines, (isReverse) ? reverseCmp : defaultCmp);
        printLines(totalLines, lines);
        return 0;
    }
    else
    {
        printf("INPUT ERROR");
        return 1;
    }
}

int defaultCmp(char *s1, char *s2)
{
    return (strcmp(s1, s2) >= 0);
}

int reverseCmp(char *s1, char *s2)
{
    return (strcmp(s1, s2) < 0);
}

void sort(char *list[], int firstIndex, int lastIndex, int (*comp)(char *s1, char *s2))
{
    if (firstIndex < lastIndex)
    {
        int i = firstIndex;
        int pivotIndex = lastIndex;

        while (i < pivotIndex)
        {

            if ((*comp)(list[i], list[pivotIndex]))
            {
                swap(list, i, (pivotIndex - 1), pivotIndex);
                pivotIndex--;
                continue;
            }

            i++;
        }
        sort(list, firstIndex, pivotIndex - 1, comp);
        sort(list, pivotIndex + 1, lastIndex, comp);
    }
}

int readLines(int maxLines, char *linesStorage[])
{
    int const LINEMAX = 100;
    char *lineBuf;
    int lineNumber = -1;

    int scanReturn = scanf("%s", lineBuf = malloc(LINEMAX));

    while (scanReturn != EOF)
    {
        lineNumber++;

        if (lineNumber >= LINEMAX || lineBuf == NULL)
        {
            return -1;
        }

        linesStorage[lineNumber] = lineBuf;
        scanReturn = scanf("%s", lineBuf = malloc(LINEMAX));
    }

    return lineNumber;
}

void printLines(int lines, char *linesStorage[])
{
    for (int i = 0; i < (lines + 1); i++)
    {
        printf("%s :", linesStorage[i]);
    }
}

void initLinesStorage(int maxLines, char *linesStorage[])
{
    for (int i = 0; i < maxLines; i++)
    {
        linesStorage[i] = NULL;
    }
}

void swap(char *list[], int a, int b, int pivote)
{
    if (pivote == 1)
    {
        char *temp = list[a];
        list[a] = list[pivote];
        list[pivote] = temp;
    }
    else
    {
        char *temp = list[a];
        list[a] = list[b];
        list[b] = list[pivote];
        list[pivote] = temp;
    }
}