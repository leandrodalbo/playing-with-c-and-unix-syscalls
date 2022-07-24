#include "stack.h"
#include "terminalReader.h"
#include <stdio.h>
#include <ctype.h>

int main()
{

    char calculation[10];

    int digits = 0;
    int operands = 0;
    int invalidElement = 0;
    int invalidOperation = 0;

    readInput(calculation, 10);

    int item = 0;

    while (calculation[item] != '\0')
    {
        char elem = calculation[item];

        if (isdigit(elem))
        {
            digits++;

            if (digits > 2)
            {
                invalidOperation = 1;
            }

            push(elem - '0');
        }
        else
        {
            int d1 = pop();
            int d2 = pop();

            switch (elem)
            {

            case '+':

                push(d2 + d1);
                digits = 0;
                break;

            case '-':

                push(d2 - d1);
                digits = 0;
                break;

            case '*':

                push(d2 * d1);
                digits = 0;
                break;

            case '/':

                push(d2 / d1);
                digits = 0;
                break;

            default:
                if (digits > 2)
                {
                    invalidOperation = 1;
                }

                invalidElement = 1;

                break;
            }
        }

        if (invalidOperation || invalidElement)
        {
            printf("unable to calculate %s \n", calculation);
            break;
        }

        item++;
    }

    printf("result : %d", pop());
}
