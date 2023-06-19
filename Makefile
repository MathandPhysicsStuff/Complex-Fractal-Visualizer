
CFLAGS = -O3 -mavx2 -lSDL2 -lSDL2main -lSDL2_ttf

all: bin

bin: main.o menu.o initalize_free.o mandelbrot.o map.o event_inputs.o
	gcc $(CFLAGS) main.o menu.o initalize_free.o mandelbrot.o map.o event_inputs.o -o bin

main.o: main.c
	gcc $(CFLACGS) -c main.c

menu.o: menu.c
	gcc $(CFLACGS) -c menu.c

initalize_free.o:
	gcc $(CFLAGS) -c initalize_free.c

mandelbrot.o: mandelbrot.c
	gcc $(CFLAGS) -c mandelbrot.c

map.o: map.c
	gcc $(CFLAGS) -c map.c

event_inputs.o: event_inputs.c
	gcc $(CFLAGS) -c event_inputs.c

clean:
	rm -f *.o bin





