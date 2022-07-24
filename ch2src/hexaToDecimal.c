#include <stdio.h>
#include <string.h>
#include <math.h>

int itoh(char hexa[]);
int getIntForHexaletter(char letter);
int getNumberDigit(char number);

int main()
{
    char hexaBuf[10];

    scanf("%s", hexaBuf);

    int decimalNumber = itoh(hexaBuf);

    if (decimalNumber == -1)
    {
        printf("error: invalid hexadecimal number.");
    }
    else
    {

        printf("decimal number: %d", itoh(hexaBuf));
    }

    return 0;
}

int itoh(char hexa[])
{
    int exponent = 0;
    int strLength = strlen(hexa);
    int intDigitsBuf[strLength];

    for (int position = (strLength - 1); position >= 0; position--)
    {

        int digit = getNumberDigit(hexa[position]);

        if (digit == -1)
        {
            digit = getIntForHexaletter(hexa[position]);
        }

        if (digit == -1)
        {
            return -1;
        }
        else
        {
            intDigitsBuf[position] = (digit * pow(16, exponent));
            exponent++;
        }
    }

    int digitsSum = 0;

    for (int i = 0; i < strLength; i++)
    {
        digitsSum += intDigitsBuf[i];
    }
    return digitsSum;
}

int getNumberDigit(char number)
{
    if (number >= '0' && number <= '9')
    {
        return (number - '0');
    }

    return -1;
}

int getIntForHexaletter(char letter)
{
    switch (letter)
    {
    case 'a':
    case 'A':
        return 10;
        break;

    case 'b':
    case 'B':
        return 11;
        break;

    case 'c':
    case 'C':
        return 12;
        break;

    case 'd':
    case 'D':
        return 13;
        break;

    case 'e':
    case 'E':
        return 14;
        break;

    case 'f':
    case 'F':
        return 15;
        break;

    default:
        return -1;
    }
}
