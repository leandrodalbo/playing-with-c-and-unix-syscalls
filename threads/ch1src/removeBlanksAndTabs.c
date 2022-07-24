#include <stdio.h>

int main()
{
    char str[20] = "ggg ffff    dddd";
    char result[20];
    int pos = 0;
    int resultTotal = 0;

    while (str[pos] != '\0')
    {
        if (str[pos] != ' ' && str[pos] != '\t')
        {
            result[resultTotal] = str[pos];
            resultTotal++;
        }

        pos++;
    }

    result[resultTotal] = '\0';

    printf("clean string : %s", result);

    return 0;
}