#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"

static node *newNode(void);

/********** public interface **********/

node *newIntNode(int val)
{
    node *p = newNode();
    p->key = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int getValue(treeNode *node)
{
    return node->key;
}

node setValue(treeNode *node, int val)
{
    node->key = val;
    return node;
}

int getLeft(treeNode *node)
{
    int value = node->left;
    return value;
}

int getRight(treeNode *node)
{
    int value = node->right;
    return value;
}

/********** private methods **********/

static treeNode *newNode()
{
    treeNode *n = (treeNode *)malloc(sizeof(treeNode));
    if (n == 0)
    {
        fprintf(stderr, "out of memory");
        exit(-1);
    }
    return n;
}
