OBJS = heapsort.o queue.o treeNode.o

heapsort: heapsort.o queue.o treeNode.o
	gcc -Wall -o heapsort heapsort.o queue.o treeNode.o

clean: 
	rm -f *.o
	rm heapsort

run: heapsort
	./heapsort integers

heap: heapsort.c queue.o treeNode.o
	gcc -Wall -g -c -o heapsort.o heapsort.c
queue: queue.c treeNode.o
	gcc -Wall -g -c -o queue.o queue.c

treeNode: treeNode.c
	gcc -Wall -g -c -o treeNode.o treeNode.c

