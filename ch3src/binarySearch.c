#include <stdio.h>

int searchIntNumber(int searched, int list[], int length);
int main()
{

    int list[] = {2, 25, 34, 56, 66, 112, 321, 554};

    printf("found int position: %d", searchIntNumber(112, list, 8));
}

int searchIntNumber(int searched, int orderedList[], int listLength)
{

    int lowest, highest, mid;

    lowest = 0;
    highest = listLength - 1;
    int fondinPosition = -1;

    while (lowest <= highest)
    {
        mid = (lowest + highest) / 2;

        if (orderedList[mid] < searched)
        {
            lowest = (mid + 1);
        }

        if (orderedList[mid] > searched)
        {
            highest = (mid - 1);
        }

        if (orderedList[mid] == searched)
        {
            fondinPosition = mid;
            break;
        }
    }
    return fondinPosition;
}