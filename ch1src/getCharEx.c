#include <stdio.h>

int main()
{
    printf("to finish enter EOF \n");
    int intCharValue = getchar();

    while (intCharValue != EOF)
    {
        putchar(intCharValue);
        intCharValue = getchar();
    }

    return 0;
}