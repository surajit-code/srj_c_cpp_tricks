IDIR =./includes/
CC=gcc
CFLAGS=-g -Wall -I $(IDIR)


binary_search_tree: binary_search_tree.o src/create_bst.o
	$(CC) -o binary_search_tree binary_search_tree.o src/create_bst.o


.PHONY: clean

clean:
	rm -f ./*.o ./binary_search_tree ./src/*.o
