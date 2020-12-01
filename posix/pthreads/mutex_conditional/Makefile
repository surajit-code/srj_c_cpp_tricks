CC=gcc
CFLAGS=-g -Wall -lpthread

conditional: conditional.o
	$(CC) $(CFLAGS) -o conditional conditional.o


.PHONY: clean

clean:
	rm -f ./*.o ./conditional
