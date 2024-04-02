CC = gcc
CFLAGS = -Wall -std=c17 -g

all: countdown

countdown: countdown.c
	$(CC) $(CFLAGS) -o countdown countdown.c

clean: 
	rm -f countdown

.PHONY: all clean