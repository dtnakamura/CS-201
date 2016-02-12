#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"

/********** public interface **********/

treeNode *newIntNode(int val)
{
    treeNode *p = (treeNode *)malloc(sizeof(treeNode));
    if (p == 0)
    {
        fprintf(stderr, "out of memory");
        return 0;
    }
    p->key = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}
