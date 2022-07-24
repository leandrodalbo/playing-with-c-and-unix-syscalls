
#define PRIORITY_LOW 1
#define PRIORITY_MEDIUM 2
#define PRIORITY_HIGH 3

#define ITEM_INIT_VALUE -1;

typedef struct NodeStruct
{
  int value;
  int priority;
  struct NodeStruct *link;
} QItem;

extern QItem *createQueue();
extern void printQueue(QItem *queue);
extern QItem *addQItem(QItem *queue, int value, int priority);
extern QItem *processQItem(QItem *queue);
extern int isEmpty(QItem *queue);
extern int isAvalidPriority(int priority);
