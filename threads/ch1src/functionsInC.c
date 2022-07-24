#include <stdio.h>

/*
A function provides a way to encapsulate some computations, which can be used without worrying about the implementation

parameter: used for the variables named in the parenthesized list
argument: a value used in a function call

arguments by value: the called function is given its values of its arguments in temporary variables
*/

int power(int base, int exp);

int main()
{
    for (int i = 0; i <= 5; i++)
    {
        printf("power(2, %d) : %d  power(-3, %d) : %d \n", i, power(2, i), i, power(-3, i));
    }

    return 0;
}

int power(int base, int exp)
{
    int result = 1;

    for (int i = 0; i <= (exp - 1); i++)
    {
        result = (result * base);
    }

    return result;
}