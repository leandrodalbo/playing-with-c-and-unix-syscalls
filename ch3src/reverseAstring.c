#include <stdio.h>
#include <string.h>

void reversed(char s[], int n);

int main()
{
    char strBuf[10];
    scanf("%s", strBuf);

    reversed(strBuf, strlen(strBuf));
    printf("reversed: %s\n", strBuf);

    return 0;
}

void reversed(char s[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }
}