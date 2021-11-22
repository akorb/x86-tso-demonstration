CC=gcc

# Disable optimization to avoid instruction reordering by the compiler
CFLAGS=-Wall -fopenmp -O0

all:
	$(CC) $(CFLAGS) -o demo demo.c

clean:
	rm demo
