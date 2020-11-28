CC=gcc
CFLAGS=-g -Wall -rdynamic


stacks_and_dumps: stacks_and_dumps.o
	$(CC) $(CFLAGS) -o stacks_and_dumps stacks_and_dumps.o


.PHONY: clean

clean:
	rm -f ./*.o ./stacks_and_dumps
