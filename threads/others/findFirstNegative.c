#include <stdio.h>
#include <stdlib.h>

#define MAXINDEX 5

void loadNumbers(int *numbers, int LASTINDEX);
void showNumbers(int numbers[], int LASTINDEX);
int firsNegativeIndex(int numbers[], int LASTINDEX);

int main()
{
  int numbers[MAXINDEX];

  loadNumbers(numbers, MAXINDEX);
 
  showNumbers(numbers, MAXINDEX);

  int firstNegative = firsNegativeIndex(numbers, MAXINDEX);
  
  if(firstNegative == -1)
  {
    printf("\n No Negative found");
  }
  else
  {
    printf("\n Negative: A[%d]=[%d] ", firstNegative, numbers[firstNegative]);
  }
  

  exit(0);

}

void loadNumbers(int *numbers, int LASTINDEX)
{
  for(int i = 0; i < MAXINDEX; i++)
  {
    scanf("%d",&numbers[i]);
  }

}

void showNumbers(int numbers[], int LASTINDEX)
{
  for(int i = 0; i < MAXINDEX; i++)
  {
    printf(" %d ,", numbers[i]);
  }
}

int firsNegativeIndex(int numbers[], int LASTINDEX)
{
  int index = 0;

  while (index < MAXINDEX)
  {
    if(numbers[index] < 0)
    {
      return index;
    }

    index++;
  
  }
  
  return -1;
}