CC=gcc
CFLAGS=-g -Wall -lpthread


mutex_calc_area: mutex_calc_area.o
	$(CC) $(CFLAGS) -o mutex_calc_area mutex_calc_area.o


.PHONY: clean

clean:
	rm -f ./*.o ./mutex_calc_area
