#include <stdio.h>

void sort(int v[], int n);

int main()
{

    int list[] = {34, 12, 55, 33, 22, 10, 1};

    sort(list, 7);

    for (int i = 0; i < 7; i++)
    {
        printf("%d:", list[i]);
    }
    return 0;
}

void sort(int v[], int n)
{

    for (int gap = (n / 2); gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            for (int j = (i - gap); j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                int temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}