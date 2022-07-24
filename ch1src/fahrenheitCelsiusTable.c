#include <stdio.h>

//symbolic constants
#define HIGHEST 300
#define STEP 20

int main()
{
    float celsius;
    int next = 0;

    while (next <= HIGHEST)
    {
        celsius = (5.0 / 9.0) * ((float)next - 32.0);
        printf("celsius=%3.2f  fahrenheit=%3.2f \n", celsius, (float)next);
        next += STEP;
    }
}