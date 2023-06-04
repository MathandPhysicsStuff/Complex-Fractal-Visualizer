
CFLAGS = -lSDL2 -lSDL2main

all: bin

bin: main.o menu.o
	gcc $(CFLAGS) main.o menu.o -o bin

main.o: main.c
	gcc $(CFLACGS) -c main.c

menu.o: menu.c
	gcc $(CFLACGS) -c menu.c

clean:
	rm -f *.o bin





