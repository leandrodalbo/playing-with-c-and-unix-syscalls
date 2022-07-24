#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODES_MAXINDEX 4
#define TOTAL_CODES 5

typedef char Code[CODES_MAXINDEX];

typedef struct NodeStruct
{
  Code code;
  struct NodeStruct *leftLink;
  struct NodeStruct *rightLink;
} Node;

Node *loadCodes();
void showListBothWays(Node *list);

int main()
{

  Node *list = loadCodes();
  printf("\n Loaded Nodes: \n");
  showListBothWays(list);

  exit(0);
}

void showListBothWays(Node *list)
{

  do
  {
    printf("%s, \t", list->code);
    list = list->rightLink;

    if (list->rightLink == NULL)
    {
      printf("%s, \n \n", list->code);
    }

  } while (list->rightLink != NULL);

  do
  {
    printf("%s, \t", list->code);
    list = list->leftLink;

    if (list->leftLink == NULL)
    {
      printf("%s, \n \n", list->code);
    }

  } while (list->leftLink != NULL);

}

Node *loadCodes()
{
  Node *list;
  Node *lastNode;
  Node *newElem;
  char codeBuf[CODES_MAXINDEX];

  for (int i = 0; i < TOTAL_CODES; i++)
  {
    newElem = (Node *)malloc(sizeof(Node));
    scanf("%s", codeBuf);
    strcpy(newElem->code, codeBuf);

    if (i == 0)
    {
      newElem->leftLink = NULL;
      newElem->rightLink = NULL;
      list = newElem;
      
    }
    else
    {
      newElem->rightLink = NULL;
      newElem->leftLink = lastNode;
      lastNode->rightLink = newElem;
      
    }
    lastNode = newElem;
  }

  return list;
}
