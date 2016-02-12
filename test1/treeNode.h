#ifndef treeNode_h_
#define treeNode_h_

typedef struct 
{
    int key;

    struct treeNode *left;
    struct treeNode *right;
    struct treeNode *parent;

} treeNode;

extern treeNode *newIntNode(int value);
extern int getValue(treeNode *node);
extern treeNode setValue(treeNode *node, int value);
extern int getLeft(treeNode *parent);
extern int getRight(treeNode *parent);

#endif
