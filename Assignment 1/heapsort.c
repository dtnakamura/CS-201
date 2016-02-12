// Program for linked implementation of binary tree
#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"
#include "queue.h"

/* DON'T NEED
// Queue size
int SIZE = 5;
*/

/* DON'T NEED
// A tree node
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
*/

/* DON'T THINK I NEED
// A queue node
struct Queue
{
    // pointer to the head
    // queue is circular so tail is head->left
    struct node * head;
    // number of elements in the queue
    int size;
};
*/

/* DON'T THINK I NEED
// A utility function to create a new tree node
struct treeNode *newIntNode(int data)
{
    struct treeNode *temp = (struct treeNode*)malloc(sizeof(struct treeNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
*/

/*
 * IMPORTANT THINGS TO REMEMBER:
 * count 4 pointer reassignments for every insertion
 * count 2 pointers and a free() for deletions
 * always check for null on delete
 *  * make sure you check boundaries before you delete
 *   - always let delete succeed and segfault if empty
 *   - return garbage (0) if empty
 */

/* DON'T THINK I NEED
// A utility function to create a new Queue
// don't need a size
struct Queue *createQueue(int size)
{
    // malloc the queue struct
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    // set the head pointer. NULL if nothing
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->array = (struct treeNode**)malloc
        (queue->size * sizeof(struct treeNode*));

    for (int i = 0; i < size; ++i)
        queue->array[i] = NULL;
    return queue;
}
*/

/* DON'T THINK I NEED
// Standard queue functions
int queueIsEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

int queueIsFull(struct Queue *queue)
{
    return queue->rear == queue->size - 1;
}

int queueHasOnlyOneItem(struct Queue *queue)
{
    return queue->front == queue->rear;
}

void enqueue(struct treeNode*root, struct Queue *queue)
{
    if (queueIsFull(queue))
    {
        SIZE *= 2;
        struct Queue *newQueue = createQueue(SIZE);
        newQueue->front = queue->front;
        newQueue->rear = queue->rear;
        for (int i = 0; i <= newQueue->size; ++i)
        {
            newQueue->array[i] = queue->array[i];
        }
        printf("Created new queue of size %d.\n", SIZE);
        //printf("newQueue-> front = %d, queue->front = %d\n", newQueue->front, queue->front);
        //printf("newQueue-> rear = %d, queue->rear = %d\n", newQueue->rear, queue->rear);
        return;
    }
    //printf("Adding item %d to existing queue.\n", root->data);
    queue->array[++queue->rear] = root;
    if (queueIsEmpty(queue))
        ++queue->front;
}

struct treeNode *removeFromFront(struct Queue *queue)
{
    if (queueIsEmpty(queue))
        return NULL;
    struct treeNode *temp = queue->array[queue->front];
    if (queueHasOnlyOneItem(queue))
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
        ++queue->front;
    return temp;
}

struct treeNode *removeFromRear(struct Queue *queue)
{
    if (queueIsEmpty(queue))
        return NULL;
    struct treeNode *temp = queue->array[queue->rear];
    if (queueHasOnlyOneItem(queue))
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
        --queue->rear;
    return temp;
}

struct treeNode *getFront(struct Queue *queue)
{
    return queue->array[queue->front];
}
*/

// A utility function to check if a tree node has both 
// left and right children
int hasBothChildren(struct treeNode *temp)
{
    return temp && temp->left && temp->right;
}

// Function to insert a new node in complete binary tree
void treeInsert(treeNode *n, struct Queue *q)
{
    // If the tree is empty, initialize the root with a new node
    if (q->size == 0)
    {
        q->head->data = n;
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
        }
        // If the right child of this front node doesn't exist;
        // set the right child as the new node
        else if (!front->right)
        {
            front->right = n;
            n->parent = front;
        }
        // If the front node has both children, dequeue it
        if (hasBothChildren(front))
        {
            struct treeNode *temp = NULL;
            temp = removeFront(q);
        }
    }
    
    // Enqueue the new node for later insertions
    addBack(q, n);
}

// Standard level-order traversal to test
void levelOrder(struct treeNode *root)
{
    struct Queue *q = createQueue();
    addBack(q, root);
    while (q->size > 0)
    {
        struct treeNode *temp = removeFront(q);
        printf("%d\n", temp->key);
        if (temp->left)
            addBack(q, temp->left);
        if (temp->right)
            addBack(q, temp->right);
    }
}

/*
// Heap things go here
void maxHeapify(struct treeNode *root)
{
    struct Queue *queue = createQueue();
    addFront(queue, root);
    while (queue->size > 0)
    {
        struct treeNode *temp = removeFront(queue);
        //printf("Dequeue'd node->data: %d\n",temp->data);
        // If left > data AND left > right, replace data with left
        
        // If right > data AND right > left, replace data with right
    }
}
*/
            
// And finally, our main function
int main(int argc, char **argv)
{
    int readInts;
    struct treeNode *root = NULL;
    struct treeNode *n = NULL;
    struct Queue *queue = createQueue();
    FILE *fp;

    fp = fopen(argv[1],"r");
    if (fp == NULL)
        printf("NO SUCH FILE EXISTS. PLEASE TRY AGAIN.");
    while (fscanf(fp, "%d", &readInts) != EOF)
    {
        n->key = readInts;
        printf("Inserting %d into tree...\n", n->key);
        treeInsert(n, queue);
    }
    fclose(fp);

    //maxHeapify(root);
    levelOrder(root);

    return 0;
}
