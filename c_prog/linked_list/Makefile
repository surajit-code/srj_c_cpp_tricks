IDIR =./includes/
CC=gcc
CFLAGS=-g -Wall -I $(IDIR)


linked_list: linked_list.o src/create_ll.o
	$(CC) -o linked_list linked_list.o src/create_ll.o


.PHONY: clean

clean:
	rm -f ./*.o ./linked_list ./src/*.o
