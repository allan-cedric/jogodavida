CC=gcc
CFLAGS=-ansi -Wall
LDLIBS=-lncurses -lm
OBJ=jogodavida.o menu.o main.o
EXEC=main

all: main clean

main: $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(CFLAGS) $(LDLIBS)

jogodavida.o: jogodavida.h jogodavida.c
	$(CC) -c jogodavida.c $(CFLAGS)

menu.o: menu.h menu.c
	$(CC) -c menu.c $(CFLAGS)

main.o: menu.h jogodavida.h main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC)