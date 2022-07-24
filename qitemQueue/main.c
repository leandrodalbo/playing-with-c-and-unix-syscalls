#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  QItem *queue = createQueue();
  char cmdBuf[5];

  do
  {

    printf("check queue operations: add, print, process, exit... \n");
    scanf("%s", cmdBuf);

    if (strcmp(cmdBuf, "add") == 0)
    {
      int p, v;

      printf("insert priority -> HIGH:%d, MEDIUM:%d, LOW:%d \n", PRIORITY_HIGH, PRIORITY_MEDIUM, PRIORITY_LOW);
      scanf("%d", &p);

      printf("insert value: \n");
      scanf("%d", &v);

      if (isAvalidPriority(p))
      {
        queue = addQItem(queue, v, p);
      }
      else
      {
        printf("Invalid priority value \n");
      }
    }

    if (strcmp(cmdBuf, "print") == 0)
    {
      if (isEmpty(queue))
      {
        printf("empty queue!!!\n");
      }
      else
      {
        printQueue(queue);
      }
    }

    if (strcmp(cmdBuf, "process") == 0)
    {
      queue = processQItem(queue);
    }

  } while (strcmp(cmdBuf, "exit") != 0);

  free(queue);
}