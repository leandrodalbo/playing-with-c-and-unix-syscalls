#include <stdio.h>

int main()
{
    int digit, whiteDigit, otherDigits;
    int results[10];

    //init results
    for (int i = 0; i < 10; i++)
    {
        results[i] = 0;
    }

    otherDigits = 0;
    whiteDigit = 0;
    digit = getchar();

    while (digit != EOF)
    {
        if (digit == ' ' || digit == '\t')
        {
            whiteDigit++;
        }
        else if (digit >= '0' && digit <= '9')
        {
            ++results[digit - '0'];
        }
        else
        {
            if (digit != '\n')
            {
                otherDigits++;
            }
        }

        digit = getchar();
    }

    printf("digits results: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d -> %d \n", i, results[i]);
    }

    printf("white digits: %d  other= %d \n", whiteDigit, otherDigits);
}