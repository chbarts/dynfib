CFLAGS = -O3 -g -Wall -ansi -pedantic -std=c99 -march=native

CC = gcc

.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) -c $<

OBJS = dynfib.o test-dynfib.o

SRCS = dynfib.c test-dynfib.c

all: test-dynfib

test-dynfib: $(OBJS)
	$(CC) $(OBJS) -o test-dynfib

clean:
	rm *.o test-dynfib
