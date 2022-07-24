#include <stdio.h>

int isLeapYear(int year);

int main()
{
    int year;

    int lastRead = scanf("%d", &year);

    while (lastRead != EOF)
    {
        printf("%d is a leap year? ==>  %d \n", year, isLeapYear(year));

        lastRead = scanf("%d", &year);
    }
}

int isLeapYear(int year)
{

    if (((year % 4) == 0) && !((year % 100) == 0))
    {
        return 1;
    }
    else
    {
        if ((year % 400) == 0)
        {
            return 1;
        }
    }

    return 0;
}