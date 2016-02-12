#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "treeNode.h"

int main(int argc, char **argv)
{
    int readInts;
    FILE *fp;
    struct Queue *q = createQueue();
    struct Queue *r = createQueue();
    struct Queue *s = createQueue();
    struct Queue *t = createQueue();

    // Add to front, remove from front
    fp = fopen("integers", "r");
    while (fscanf(fp, "%d", &readInts) != EOF)
    {
        struct treeNode *temp1 = newIntNode(readInts);
        addFront(q, temp1);
        printf("Added %d to front of queue.\n", readInts);
    }
    fclose(fp);
    while (q->size > 0)
    {
        printf("Removed %d from front of queue.\n", (int)removeFront(q)->key);
    }
    printf("\n");

    // Add to front, remove from rear
    fp = fopen("integers", "r");
    while (fscanf(fp, "%d", &readInts) != EOF)
    {
        struct treeNode *temp2 = newIntNode(readInts);
        addFront(r, temp2);
        printf("Added %d to front of queue.\n", readInts);
    }
    fclose(fp);
    while (r->size > 0)
    {
        printf("Removed %d from back of queue.\n", (int)removeBack(r)->key);
    }
    printf("\n");

    // Add to back, remove from front
    fp = fopen("integers", "r");
    while (fscanf(fp, "%d", &readInts) != EOF)
    {
        struct treeNode *temp3 = newIntNode(readInts);
        addBack(s, temp3);
        printf("Added %d to back of queue.\n", readInts);
    }
    fclose(fp);
    while (s->size > 0)
    {
        printf("Removed %d from front of queue.\n", (int)removeFront(s)->key);
    }
    printf("\n");

    // Add to back, remove from back
    fp = fopen("integers", "r");
    while (fscanf(fp, "%d", &readInts) != EOF)
    {
        struct treeNode *temp4 = newIntNode(readInts);
        addBack(t, temp4);
        printf("Added %d to back of queue.\n", readInts);
    }
    fclose(fp);
    while (t->size > 0)
    {
        printf("Removed %d from back of queue.\n", (int)removeBack(t)->key);
    }
}
