#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

QItem *createQueue()
{

  QItem *queue = (QItem *)malloc(sizeof(QItem));

  queue->value = ITEM_INIT_VALUE;
  queue->priority = ITEM_INIT_VALUE;
  queue->link = NULL;

  return queue;
}

void printQueue(QItem *queue)
{
  while (queue != NULL)
  {
    printf(" queue value : %i \n", queue->value);

    queue = queue->link;
  }
}

QItem *addQItem(QItem *queue, int value, int priority)
{
  QItem *newItem = (QItem *)malloc(sizeof(QItem));

  newItem->value = value;
  newItem->priority = priority;

  if (isEmpty(queue))
  {
    queue->value = value;
    queue->priority = priority;
  }
  else if (!isEmpty(queue) && priority <= queue->priority)
  {
    newItem->link = queue;
    queue = newItem;
  }
  else
  {
    QItem *aux = queue;
    QItem *prev = queue;
    while (aux->link != NULL && priority > aux->priority)
    {
      prev = aux;
      aux = aux->link;
    }

    if (aux->link == NULL)
    {
      if (priority > aux->priority)
      {
        newItem->link = NULL;
        aux->link = newItem;
      }
      else
      {
        prev->link = newItem;
        newItem->link = aux;
      }
    }
    else
    {
      prev->link = newItem;
      newItem->link = aux;
    }
  }

  return queue;
}

QItem *processQItem(QItem *queue)
{

  if (queue->link == NULL)
  {
    free(queue);
    queue = NULL;
  }
  else
  {

    QItem *item = queue;
    QItem *prev = queue;

    while (item->link != NULL)
    {
      prev = item;
      item = item->link;
    }

    prev->link = NULL;
    free(item);
  }

  return queue;
}

int isEmpty(QItem *queue)
{
  return (queue == NULL || queue->value == -1);
}

int isAvalidPriority(int priority)
{
  return (priority >= PRIORITY_LOW && priority <= PRIORITY_HIGH);
}