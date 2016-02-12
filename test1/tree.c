// Sauce:
// http://www.geeksforgeeks.org/linked-complete-binarty-tree-its-creation/

// Program for linked implementation of binary tree
#include <stdio.h>
#include <stdlib.h>

// Queue size
int SIZE = 5;

// A tree node
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

// A queue node
struct Queue
{
    int front, rear, size;
    struct node* *array;
};

// A utility function to create a new tree node
struct node *newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// A utility function to create a new Queue
struct Queue *createQueue(int size)
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->array = (struct node**)malloc
        (queue->size * sizeof(struct node*));

    for (int i = 0; i < size; ++i)
        queue->array[i] = NULL;
    return queue;
}

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

void enqueue(struct node *root, struct Queue *queue)
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

struct node *removeFromFront(struct Queue *queue)
{
    if (queueIsEmpty(queue))
        return NULL;
    struct node *temp = queue->array[queue->front];
    if (queueHasOnlyOneItem(queue))
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
        ++queue->front;
    return temp;
}

struct node *removeFromRear(struct Queue *queue)
{
    if (queueIsEmpty(queue))
        return NULL;
    struct node *temp = queue->array[queue->rear];
    if (queueHasOnlyOneItem(queue))
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
        --queue->rear;
    return temp;
}

struct node *getFront(struct Queue *queue)
{
    return queue->array[queue->front];
}

// A utility function to check if a tree node has both 
// left and right children
int hasBothChildren(struct node *temp)
{
    return temp && temp->left && temp->right;
}

// Function to insert a new node in complete binary tree
void treeInsert(struct node **root, int data, struct Queue *queue)
{
    // Create a new node for give data
    struct node *temp = newNode(data);

    // If the tree is empty, initialize the root with a new node
    if (!*root)
        *root = temp;
    else
    {
        // get the front node of the queue
        struct node *front = getFront(queue);

        // If the left child of this front node doesn't exist,
        // set the left child as the new node
        if (!front->left)
            front->left = temp;
        // If the right child of this front node doesn't exist;
        // set the right child as the new node
        else if (!front->right)
            front->right = temp;
        // If the front node has both children, dequeue it
        if (hasBothChildren(front))
            removeFromFront(queue);
    }
    // Enqueue the new node for later insertions
    enqueue(temp, queue);
}

// Standard level-order traversal to test
void levelOrder(struct node *root)
{
    struct Queue *queue = createQueue(SIZE);
    enqueue(root, queue);
    while (!queueIsEmpty(queue))
    {
        struct node *temp = removeFromFront(queue);
        printf("%d\n", temp->data);
        if (temp->left)
            //printf("adding temp->left to queue\n");
            enqueue(temp->left, queue);
        if (temp->right)
            //printf("adding temp->right to queue\n");
            enqueue(temp->right, queue);
    }
}

// Heap things go here
void maxHeapify(struct node *root)
{
    struct Queue *queue = createQueue(SIZE);
    enqueue(root, queue);
    while (!queueIsEmpty(queue))
    {
        struct node *temp = removeFromFront(queue);
        /*
         printf("Dequeue'd node->data: %d\n",temp->data);
        // If left > data AND left > right, replace data with left
        if ((temp->left->data > temp->data) && (temp->left->data > temp->right->data))
        {
            printf("Left child %d was greater than %d. Moving %d to back of queue...\n", temp->left->data, temp->data, temp->data);
            struct node *swapA = newNode(temp->left->data);
            printf("swapA->data = %d\n", swapA->data);
            if (temp->left)
            {
                swapA->left = temp;
                printf("temp->left copied to swapA->left. swapA->left value is %d\n", swapA->left->data);
            }
            if (temp->right)
            {
                swapA->right = temp->right;
                printf("temp->right copied to swapA->right. swapA->right value is %d\n", swapA->right->data);
            }
            temp->data = temp->left->data;
            printf("New temp->data: %d\n", temp->data);
            enqueue(swapA, queue);
            printf("Successfully enqueue'd swapA\n");
        }
        // If right > data AND right > left, replace data with right
        else if ((temp->right->data > temp->data) && (temp->right->data > temp->left->data))
        {
            printf("Right child %d was greater than %d. Moving %d to back of queue...\n", temp->right->data, temp->data, temp->data);
            struct node *swapB = newNode(temp->right->data);
            printf("swapB->data = %d\n", swapB->data);
            if (temp->left)
            {
                swapB->left = temp->left;
                printf("temp->left copied to swapB->left. swapB->left value is %d\n", swapB->left->data);
            }
            if (temp->right)
            {
                swapB->right = temp;
                printf("temp->right copied to swapB->right. swapB->right value is %d\n", swapB->right->data);
            }
            temp->data = temp->right->data;
            printf("New temp->data: %d\n", temp->data);
            enqueue(swapB, queue);
            printf("Successfully enqueue'd swapB\n");
        }
        */
        if (temp->left)
        {
            printf("Enqueue'ing %d...\n", temp->left->data);
            enqueue(temp->left, queue);
        }
        if (temp->right)
        {
            printf("Enqueue'ing %d...\n", temp->right->data);
            enqueue(temp->right, queue);
        }
        //if (temp->left == NULL && temp->right == NULL)
            //printf("Node with %d value has no children\n", temp->data);
    }
    printf("%d\n", removeFromRear(queue)->data);
}
            
int main(int argc, char **argv)
{
    int readInts;
    struct node *root = NULL;
    struct Queue *queue = createQueue(SIZE);
    FILE *fp;

    fp = fopen(argv[1],"r");
    if (fp == NULL)
        printf("NO SUCH FILE EXISTS. PLEASE TRY AGAIN.");
    while (fscanf(fp, "%d", &readInts) != EOF)
    {
        //printf("Inserting %d into tree...\n", readInts);
        treeInsert(&root, readInts, queue);
    }
    fclose(fp);

    //for (int i = 0; i <= 12; ++i)
    //  treeInsert(&root, i, queue);
    //maxHeapify(root);
    levelOrder(root);
    printf("SIZE is %d\n", SIZE);

    return 0;
}
