#include <stdio.h>
#include <stdlib.h>

struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
}

struct bstNode *Insert(struct bstNode *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
bool Search(struct bstNode *root, int data)
{
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}
int main()
{
    struct bstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    int number;
    printf("Enter number to be searched\n");
    scanf();
    if (Search(root, number) == true)
        printf("Found\n");
    else
        printf("Not found\n");
}
