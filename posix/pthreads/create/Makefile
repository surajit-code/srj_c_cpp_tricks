CC=gcc
CFLAGS=-g -Wall -lpthread


pthread_creation: pthread_creation.o
	$(CC) $(CFLAGS) -o pthread_creation pthread_creation.o


.PHONY: clean

clean:
	rm -f ./*.o ./pthread_creation
