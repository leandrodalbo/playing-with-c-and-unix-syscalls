#include <stdio.h>

void sort(int list[], int firstIndex, int lastIndex);
void swap(int *a, int *b, int *pivote, int pivotIndex);
void swap2(int *a, int *b);

int main()
{

    int numbers[] = {34, 48, 5, 66, 88, 91, 15, 32, 32, 22, 1, 72, 26, 12, 2};

    sort(numbers, 0, 14);

    for (int i = 0; i < 15; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}

void sort(int list[], int firstIndex, int lastIndex)
{
    if (firstIndex < lastIndex)
    {
        char pivot = list[lastIndex];

        int i = firstIndex;
        int pivotIndex = lastIndex;

        while (i < pivotIndex)
        {

            if (list[i] > pivot)
            {
                swap(&list[i], &list[pivotIndex - 1], &list[pivotIndex], pivotIndex);
                pivotIndex--;
                continue;
            }

            i++;
        }
        sort(list, firstIndex, pivotIndex - 1);
        sort(list, pivotIndex + 1, lastIndex);
    }
}

void swap(int *a, int *b, int *pivote, int pivotIndex)
{
    if (pivotIndex == 1)
    {
        int t = *a;
        *a = *pivote;
        *pivote = t;
    }
    else
    {

        int t = *a;
        *a = *b;
        *b = *pivote;
        *pivote = t;
    }
}
