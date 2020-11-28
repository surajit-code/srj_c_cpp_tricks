CC=gcc
CFLAGS=-g -Wall -lpthread


pt_argument_passing: pt_argument_passing.o
	$(CC) $(CFLAGS) -o pt_argument_passing pt_argument_passing.o


.PHONY: clean

clean:
	rm -f ./*.o ./pt_argument_passing
