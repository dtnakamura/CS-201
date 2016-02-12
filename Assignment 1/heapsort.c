// Program for linked implementation of binary tree
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include "treeNode.h"
#include "queue.h"

int vFlag = 0;
int dFlag = 0;

// A utility function to check if a tree node has both 
// left and right children
int hasBothChildren(struct treeNode *temp)
{
    return temp && temp->left && temp->right;
}

// Function to insert a new node in complete binary tree
void treeInsert(struct Queue *q, treeNode *n, struct Queue *stack)
{
    // If the tree is empty, initialize the root with a new node
    if (q->size == 0)
    {
        addBack(q, n);
    }
    else
    {
        // get the front node of the queue
        struct treeNode *front = removeFront(q);

        // If the left child of this front node doesn't exist,
        // set the left child as the new node
        if (!front->left)
        {
            front->left = n;
            n->parent = front;
            addBack(q, front->left);
            addFront(q, front);
            //printf("added left child\n");
        }
        // If the right child of this front node doesn't exist;
        // set the right child as the new node
        else if (!front->right)
        {
            front->right = n;
            n->parent = front;
            addBack(q, front->right);
            addBack(stack, front);
            //printf("added right child\n");
        }
    }
}

// Level-order traversal to test
void levelOrder(struct Queue *q)
{
    while (q->size > 0)
    {
        struct treeNode *temp = removeBack(q);
        if (temp->left)
            addBack(q, temp->left);
        if (temp->right)
            addBack(q, temp->right);
    }
}

// Heap things go here
void maxHeapify(struct treeNode *n)
{
    int temp;
    treeNode *largest;
    // If left > data AND left > right, replace data with left
    if ((n->left) && (n->left->key > n->key))
        largest = n->left;
    else
        largest = n;
         
    // If right > data AND right > left, replace data with right
    if ((n->right) && (n->right->key > largest->key))
        largest = n->right;

    // If largest != n do the swap-y thing
    if (largest != n)
    {
        temp = n->key;
        n->key = largest->key;
        largest->key = temp;
        maxHeapify(largest);
    }
}

int
ProcessOptions(int argc, char **argv)
{
    int argIndex;
    int argUsed;
    int separateArg;
    char *arg;

    argIndex = 1;

    while (argIndex < argc && *argv[argIndex] == '-')
        {
            /* check if stdin, represented by "-" is an argument */
            /* if so, the end of options has been reached */
            if (argv[argIndex][1] == '\0') return argIndex;

            separateArg = 0;
            argUsed = 0;

            if (argv[argIndex][2] == '\0')
                {
                    arg = argv[argIndex+1];
                    separateArg = 1;
                }
            else
                arg = argv[argIndex]+2;

            switch (argv[argIndex][1])
                {
                    /*
                    * when option has an argument, do this
                    *
                    * examples are -m4096 or -m 4096
                    *
                    *   case 'm':
                    *   MemorySize = atol(arg);
                    *   argUsed = 1;
                    *   break;
                    *
                    *
                    * when option does not have an argument, do this
                    *
                    *   example is -a
                    *
                    *   case 'a':
                    *       PrintActions = 1;
                    *       break;
                    */

                    case 'd':
                        dFlag = 1;
                        break;
                    case 'v':
                        vFlag = 1;
                        break;
                    default:
                        printf("option %s not understood\n",argv[argIndex]);
                }

            if (separateArg && argUsed)
                ++argIndex;

            ++argIndex;
            }

    return argIndex;
}
           
// And finally, our main function
int main(int argc, char **argv)
{
    clock_t t;
    t = clock();
    int readInts = 0;
    struct treeNode *temp = NULL;
    struct treeNode *n = NULL;
    struct treeNode *root = NULL;
    struct Queue *queue = createQueue();
    struct Queue *stack = createQueue();
    FILE *fp;

    // FILE I/O for integers goes here
    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("NO SUCH FILE EXISTS. PLEASE TRY AGAIN.");
    }
    while (fscanf(fp, "%d\n", &readInts) != EOF)
    {
        n = newIntNode(readInts);
        if (root == NULL)
            root = n;
        treeInsert(queue, n, stack);
    }
    fclose(fp);

    while (queue->size > 0)
    {
        temp = removeFront(queue);
        addBack(stack, temp);
    }

    while (stack->size > 0)
    {
        temp = removeBack(stack);
        maxHeapify(temp);
        addBack(queue, temp);
    }

    while (queue->size > 0)
    {
        //printf("%d\n", root->key);
        treeNode *backNode = removeFront(queue);
        root->key = backNode->key;
        if (backNode->parent != NULL)
        {
            if (backNode->parent->left == backNode)
            {
                backNode->parent->left = NULL;
            }
            else
            {
                backNode->parent->right = NULL;
            }
        }
        free(backNode);
        maxHeapify(root);
    }
    t = clock() - t;
    // timeTaken has units of seconds
    double timeTaken = t/CLOCKS_PER_SEC;  
    printf("CLOCKS_PER_SEC = %f\n", CLOCKS_PER_SEC);
    printf("Project took %f seconds.\n", timeTaken);
        
    return 0;
}
