IDIR =./includes/
CC=gcc
CFLAGS=-g -Wall -I $(IDIR)


detect_loop: detect_loop.o src/create_ll.o src/detect_ll_loop.o
	$(CC) -o detect_loop detect_loop.o src/create_ll.o src/detect_ll_loop.o


.PHONY: clean

clean:
	rm -f ./*.o ./detect_loop ./src/*.o
