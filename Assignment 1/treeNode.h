#ifndef treeNode_h_
#define treeNode_h_

// node to go in a binary tree
// takes int value along with left, right, and parent pointers
typedef struct treeNode
{
    int key;
    struct treeNode *left;
    struct treeNode *right;
    struct treeNode *parent;

} treeNode;

// public functions
extern treeNode *newIntNode(int value);
extern int getValue(treeNode *node);
extern treeNode setValue(treeNode *node, int value);
extern int getLeft(treeNode *parent);
extern int getRight(treeNode *parent);

#endif
