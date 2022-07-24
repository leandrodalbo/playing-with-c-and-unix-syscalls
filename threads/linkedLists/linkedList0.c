#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODES_MAXINDEX 4

typedef char Code[CODES_MAXINDEX];

typedef struct NodeStruct
{
  Code code;
  struct NodeStruct *link;
} Node;

Node *loadDefaults();
void showList(Node *list);
void insertSecond(Node *list, Code code);
Node *findNodeWithSeqSearch(Node *list, Code code);
void deleteNode(Node *list, Code code);
Node *insertFirst(Node *list, Code code);
Node *reverse(Node *list);

int main()
{

  Node *list = loadDefaults();
  printf("\n defaultList: \n");
  showList(list);

  Code newCode = "cbu";
  insertSecond(list, newCode);
  printf("\n List update -> \n");
  showList(list);

  printf("\nSeqSearch -> \n");
  Node *foundNode = findNodeWithSeqSearch(list, newCode);

  if (foundNode != NULL)
  {
    printf("\n found node : %s \n", foundNode->code);
  }

  printf("\n List update deleting-> %s\n", newCode);
  deleteNode(list, newCode);
  showList(list);

  printf("\n List update add first-> %s\n", newCode);
  list = insertFirst(list, newCode);
  showList(list);

  printf("\n Reverser-> \n");
  Node *rever = reverse(list);
  showList(rever);

  exit(0);
}

Node *reverse(Node *list)
{
  Node *newFirst = NULL;
  Node *aux = NULL;

  while (list->link != NULL)
  {

    aux = insertFirst(newFirst, list->code);
    newFirst = aux;

    list = list->link;

    if (list->link == NULL)
    {
      aux = insertFirst(newFirst, list->code);
      newFirst = aux;
    }
  }

  return newFirst;
}

Node *insertFirst(Node *list, Code code)
{
  Node *elem = (Node *)malloc(sizeof(Node));

  if (list == NULL)
  {

    elem->link = NULL;
  }
  else
  {

    elem->link = list;
  }

  strcpy(elem->code, code);

  return elem;
}

void deleteNode(Node *list, Code code)
{
  Node *prev = NULL;
  int found = 0;

  while ((list->link != NULL))
  {
    if (strcmp(list->code, code) == 0)
    {
      found = 1;
      break;
    }

    prev = list;
    list = list->link;
  }

  if (found > 0)
  {
    prev->link = list->link;
    free(list);
  }
}

Node *findNodeWithSeqSearch(Node *list, Code code)
{
  while (list->link != NULL)
  {
    if (strcmp(list->code, code) == 0)
    {
      return list;
    }

    list = list->link;
  }

  return NULL;
}

void showList(Node *list)
{

  do
  {
    printf("%s, \t", list->code);
    list = list->link;

    if (list->link == NULL)
    {
      printf("%s, \n \n", list->code);
    }

  } while (list->link != NULL);
}

Node *loadDefaults()
{
  Node *list;
  Node *elem;

  for (int i = 0; i < 2; i++)
  {
    elem = (Node *)malloc(sizeof(Node));

    if (i == 0)
    {
      strcpy(elem->code, "abc");
      elem->link = NULL;
      list = elem;
    }
    else
    {

      strcat(elem->code, "cba");
      elem->link = NULL;
      list->link = elem;
    }
  }

  return list;
}

void insertSecond(Node *list, Code code)
{
  Node *newElem = (Node *)malloc(sizeof(Node));
  strcpy(newElem->code, code);
  newElem->link = list->link;
  list->link = newElem;
}