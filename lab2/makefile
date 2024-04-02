CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
OBJECTS = libcol.a libcol.so
CLIENTS = static_client shared_client dynamic_client
AFILES = static_client_asm.txt shared_client_asm.txt dynamic_client_asm.txt 

all: $(CLIENTS) $(AFILES)

dynamic_client_asm.txt: dynamic_client
	objdump -d dynamic_client > dynamic_client_asm.txt

shared_client_asm.txt: shared_client
	objdump -d shared_client > shared_client_asm.txt

static_client_asm.txt: static_client
	objdump -d static_client > static_client_asm.txt

#klient wyk bibl dynamiczna
dynamic_client: main.c libcol.so
	$(CC) $(CFLAGS) -o dynamic_client main.c -ldl -DDYNAMIC_LIB 

#klient wyk bibl wspoldzielona
# -Wl to linker
shared_client: main.c libcol.so
	$(CC) $(CFLAGS) -o shared_client main.c -L. -Wl,-rpath,. -lcol
	

#klien wykorzystujacy bibl stat
static_client: main.c libcol.a
	$(CC) $(CFLAGS) -o static_client main.c -L. -lcol

#biblioteka wspoldzielona:
libcol.so: collatz.o
	$(CC) $(CFLAGS) -fPIC -shared -o libcol.so collatz.o

#biblioteka statyczna:
libcol.a: collatz.o
	ar rcs libcol.a collatz.o 

collatz.o: collatz.c collatz.h
	$(CC) $(CFLAGS) -c collatz.c

clean:
	rm *.o $(OBJECTS) $(CLIENTS) $(AFILES)

.PHONY: all clean