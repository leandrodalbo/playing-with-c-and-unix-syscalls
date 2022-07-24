#include <stdio.h>
#include <string.h>

/*
write a function that deletes each character in s1 that matches any character in s2.
*/

void cleanString(char s1[], char s2[]);

int main()
{
    char strBuf0[10];
    char strBuf1[10];

    scanf("%s", strBuf0);
    scanf("%s", strBuf1);

    cleanString(strBuf0, strBuf1);

    printf("result : %s", strBuf0);

    return 0;
}

void cleanString(char s1[], char s2[])
{

    int charPosS1 = 0;
    int charPosS2;

    while (s1[charPosS1] != '\0')
    {
        charPosS2 = 0;

        while (s2[charPosS2] != '\0')
        {
            if (s1[charPosS1] == s2[charPosS2])
            {
                break;
            }
            charPosS2++;
        }

        if (s2[charPosS2] != '\0')
        {
            int actPos = charPosS1;
            while (s1[actPos] != '\0')
            {
                int nextPos = actPos + 1;
                s1[actPos] = s1[nextPos];
                actPos++;
            }
        }
        else
        {
            charPosS1++;
        }
    }
}