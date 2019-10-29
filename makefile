all: main.o llist.o
	gcc -o program main.o llist.o

main.o: main.c llist.c llist.h
	gcc -c main.c

llist.o: llist.c llist.h
	gcc -c llist.c

run:
	./program

clean:
	rm *.o
	rm *.gch