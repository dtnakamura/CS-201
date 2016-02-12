#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "treeNode.h"

extern Queue *createQueue(void) 
{
    Queue * q = (Queue *) malloc(sizeof(Queue));
    q->head = NULL;
    q->size = 0;
    return q;
}

extern void addFront(Queue *q, treeNode *treeN)
{
    struct node *n =  malloc(sizeof(node));
    n->data = treeN;
    if (q->head == NULL)
    {
        q->head = n;
        n->left = n;
        n->right = n;
    }
    else
    {
        n->right = q->head;
        n->left = q->head->left;
        n->left->right = n;
        n->right->left = n;
        q->head = n;
    }
    q->size += 1;
}

extern void addBack(Queue *q, treeNode *treeN)
{
    struct node *n = malloc(sizeof(node));
    n->data = treeN;
    if (q->head == NULL)
    {
        q->head = n;
        n->left = n;
        n->right = n;
    }
    else
    {
        n->left = q->head->left;
        n->right = q->head;
        n->left->right = n;
        n->right->left = n;
    }
    q->size += 1;
}

extern treeNode *removeFront(Queue *q)
{
    if (q->head == NULL)
    {
        return NULL;
    }
    node *n = q->head;
    if (q->size == 1)
    {
        q->head = NULL;
    }
    else
    {
        q->head = n->right;
        n->left->right = n->right;
        n->right->left = n->left;
    }
    q->size -= 1;
    treeNode *temp = n->data;
    free(n);
    return temp;
} 

extern treeNode *removeBack(Queue *q)
{
    if (q->size == 0)
    {
        return NULL;
    }
    node *n = q->head->left;
    if (q->size == 1)
    {
        q->head = NULL;
    }
    else
    {
        q->head->left = n->left;
        n->left->right = q->head;
    }
    q->size -= 1;
    treeNode *temp = n->data;
    free(n);
    return temp;
}

extern void destroy(Queue *q)
{
    free(q);
}

void printQueue(Queue *q)
{
    struct node *n = q->head;
    int i;
    for (i = 0; i < q->size; i++)
    {
        printf("%d ",n->data->key);
        n = n->right;
    }
    printf("\n");
}
