#ifndef queue_h 
#define queue_h 

#include "treenode.h"

// creates node which has treeNode as payload and has left and right pointers
// FOR LINKED LISTS ONLY!!!
typedef struct node
{
    treeNode *data;
    struct node *left;
    struct node *right;
} node;

typedef struct Queue 
{
    struct node *head;
    int size;
} Queue;

// public funcions
extern Queue *createQueue(void);
extern void addFront(Queue *q, treeNode * node);
extern void addBack(Queue *q, treeNode * node);
extern treeNode *removeFront(Queue *q);
extern treeNode *removeBack(Queue *q);
extern void destroy(Queue *q);

#endif
