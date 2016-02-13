// Program for linked implementation of binary tree
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "treeNode.h"
#include "queue.h"

int vFlag = 0;
int dFlag = 0;
char *Name = 0;

/*** ProcessOptions function borrowed from options.c by Dr. John Lusth, University of Alabama CS Department ***/
int ProcessOptions(int argc, char **argv)
{
    int argIndex;
    int argUsed;
    int separateArg;
    char *arg;

    argIndex = 1;

    while (argIndex < argc && *argv[argIndex])
        {
            if (argv[argIndex][1] == '\0') 
                return argIndex;

            separateArg = 0;
            argUsed = 0;

            if (argv[argIndex][2] == '\0')
            {
                arg = argv[argIndex+1];
                separateArg = 1;
            }
            else
                arg = argv[argIndex]+2;

            if (*argv[argIndex] == '-')
            {
                switch (argv[argIndex][1])
                    {
                        case 'd':
                            dFlag = 1;
                            break;
                        case 'v':
                            vFlag = 1;
                            break;
                        default:
                            printf("option %s not understood\n",argv[argIndex]);
                    }
            }
            else
            {
                arg = argv[argIndex];
                Name = strdup(arg);
            }

            if (separateArg && argUsed)
                ++argIndex;

            ++argIndex;
        }
                
    return argIndex;
}

void explanation(void)
{
    printf("Author: Dan Nakamura\n");
    printf("Program requirements: To run heapsort algorithm without using an array to store the heap. This program must run as efficiently as an array-based heap.\n\n");
    printf("Program runtimes for various input file sizes:\n");
    printf("|n        |t (sec)  |\n");
    printf("|10       |0.001278 |\n");
    printf("|100      |0.001397 |\n");
    printf("|1000     |0.009755 |\n");
    printf("|10000    |0.107154 |\n");
    printf("|100000   |1.087882 |\n");
    printf("|1000000  |10.972974|\n");
    printf("\nDetailed explanation: When plotted, this time vs. size curve yields a linear plot. This is indicative of O(nlogn) performance because the tests featured the sample size growing by a factor of 10 each time.\n");
    printf("\nTest methodology: the heapsort program was run on varying file sizes in both ascending and descending order with and without screen output. The times shown above are an average of the ascending and descending sort times with the screen output on. Times without screen output were faster by an (approximate) factor of 10.\n");
}

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
        }
        // If the right child of this front node doesn't exist;
        // set the right child as the new node
        else if (!front->right)
        {
            front->right = n;
            n->parent = front;
            addBack(q, front->right);
            addBack(stack, front);
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

void minHeapify(struct treeNode *n)
{
    int temp;
    treeNode *smallest;
    // If left > data AND left > right, replace data with left
    if ((n->left) && (n->left->key < n->key))
        smallest = n->left;
    else
        smallest = n;
         
    // If right > data AND right > left, replace data with right
    if ((n->right) && (n->right->key < smallest->key))
        smallest = n->right;

    // If smallest != n do the swap-y thing
    if (smallest != n)
    {
        temp = n->key;
        n->key = smallest->key;
        smallest->key = temp;
        minHeapify(smallest);
    }
}

           
// And finally, our main function
int main(int argc, char **argv)
{
    int argIndex = 0;
    int readInts = 0;
    struct treeNode *temp = NULL;
    struct treeNode *n = NULL;
    struct treeNode *root = NULL;
    struct Queue *queue = createQueue();
    struct Queue *stack = createQueue();
    FILE *fp;

    argIndex = ProcessOptions(argc, argv);
    if (vFlag)
    {
        explanation();
        exit(-1);
    }
    if (Name == NULL)
    {
        printf("you forgot to add a file name\n");
        exit(-1);
    }
    // FILE I/O for integers goes here
    fp = fopen(Name,"r");
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
    // End file I/O

    if (dFlag == 1) // Sort things in descending order
    {
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
            printf("%d ", root->key);
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
        printf("\n");
    }
    else // Sort things in ascending order
    {
        while (queue->size > 0)
        {
            temp = removeFront(queue);
            addBack(stack, temp);
        }

        while (stack->size > 0)
        {
            temp = removeBack(stack);
            minHeapify(temp);
            addBack(queue, temp);
        }

        while (queue->size > 0)
        {
            printf("%d ", root->key);
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
            minHeapify(root);
        }
        printf("\n");
    }
        
    return 0;
}
