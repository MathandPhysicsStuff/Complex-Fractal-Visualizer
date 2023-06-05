
CFLAGS = -lSDL2 -lSDL2main -lSDL2_ttf

all: bin

bin: main.o menu.o initalize_free.o 
	gcc $(CFLAGS) main.o menu.o initalize_free.o -o bin

main.o: main.c
	gcc $(CFLACGS) -c main.c

menu.o: menu.c
	gcc $(CFLACGS) -c menu.c

initalize_free.o:
	gcc $(CFLAGS) -c initalize_free.c

clean:
	rm -f *.o bin





