IDIR =./includes/
CC=gcc
CFLAGS=-g -Wall -std=c99 -I $(IDIR)


balance_bst: balance_bst.o src/create_bst.o
	$(CC) $(CFLAGS) -o balance_bst balance_bst.o src/create_bst.o


.PHONY: clean

clean:
	rm -f ./*.o ./balance_bst ./src/*.o
