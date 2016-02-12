OBJS = heapsort.o queue.o treeNode.o

heapsort: $(OBJS)
	gcc -Wall -g -o heapsort $(OBJS)

clean: 
	rm -f *.o

heap: heapsort.c queue.o treeNode.o
	gcc -Wall -g -c -o heapsort.o heapsort.c
queue: queue.c treeNode.o
	gcc -Wall -g -c -o queue.o queue.c

treeNode: treeNode.c
	gcc -Wall -g -c -o treeNode.o treeNode.c

