#include <stdio.h>

void sort(int list[], int firstIndex, int lastIndex);
int partition(int list[], int l, int h);
void swap(int *a, int *b);

int main()
{

    int numbers[] = {34, 12, 5, 66, 18, 33};

    sort(numbers, 0, 5);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}

int partition(int list[], int l, int h)
{
    int pivot = list[h];
    int i = (l - 1);

    for (int j = l; j < h; j++)
    {
        if (list[j] <= pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }

    i++;
    swap(&list[i], &list[h]);
    return i;
}

void sort(int list[], int firstIndex, int lastIndex)
{
    if (firstIndex < lastIndex)
    {
        int pi = partition(list, firstIndex, lastIndex);

        sort(list, firstIndex, pi - 1);
        sort(list, pi + 1, lastIndex);
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}