#include <stdio.h>

int main()
{
    int results[31];
    char buf[31];
    for (int i = 0; i < 31; i++)
    {
        results[i] = 0;
    }

    buf[0] = '\0';

    while (fgets(buf, sizeof(buf), stdin) != NULL)
    {
        int charpos = 0;
        int wordLength = 0;

        while ((buf[charpos] != '\0') && (buf[charpos] != '\n'))
        {
            wordLength++;
            charpos++;
        }

        ++results[wordLength];
        buf[0] = '\0';
    }

    printf("process finished!!! \n");

    for (int i = 0; i < 31; i++)
    {
        printf("%d char words :", i);

        for (int j = 0; j < results[i]; j++)
        {
            printf("|");
        }

        printf("-\n");
    }
}