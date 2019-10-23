all: main.o llist.o
	gcc -o program main.c llist.c

main.o: main.c llist.c llist.h
	gcc -c main.c

llist.o: llist.c
	gcc -c llist.c

run:
	./program

clean:
	rm *.o