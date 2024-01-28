#set noexpandtab

CFLAGS = -O2 -mavx2 -lm -lSDL2 -lSDL2main -lSDL2_ttf 

all: bin

bin: main.o menu.o event_inputs.o colors.o initalize_free.o mandelbrot.o burningship.o mandelbar.o julia.o buffalo.o celtic.o perp_burningship.o sharkfin.o sockpuppet.o alien.o crown.o pointed_celtic.o more_fractals.o
	gcc $(CFLAGS) main.o menu.o  event_inputs.o colors.o initalize_free.o mandelbrot.o burningship.o mandelbar.o julia.o buffalo.o celtic.o perp_burningship.o sharkfin.o sockpuppet.o alien.o crown.o pointed_celtic.o more_fractals.c -o bin

main.o: main.c
	gcc $(CFLACGS) -c main.c

menu.o: menu.c
	gcc $(CFLACGS) -c menu.c

event_inputs.o: event_inputs.c
	gcc $(CFLAGS) -c event_inputs.c

colors.o: colors.c
	gcc $(CFLAGS) -c colors.c

initalize_free.o: initalize_free.c
	gcc $(CFLAGS) -c initalize_free.c

mandelbrot.o: mandelbrot.c
	gcc $(CFLAGS) -c mandelbrot.c

burningship.o: burningship.c
	gcc $(CFLAGS) -c burningship.c

mandelbar.o: mandelbar.c
	gcc $(CFLAGS) -c mandelbar.c

julia.o: julia.c
	gcc $(CFLAGS) -c julia.c

buffalo.o: buffalo.c
	gcc $(CFLAGS) -c buffalo.c

celtic.o: celtic.c
	gcc $(CFLAGS) -c celtic.c

perp_burningship.o: perp_burningship.c
	gcc $(CFLAGS) -c perp_burningship.c

sharkfin.o: sharkfin.c
	gcc $(CFLAGS) -c sharkfin.c

sockpupper.o: sockpuppet.c
	gcc $(CFLAGS) -c sockpuppet.c

alien.o: alien.c
	gcc $(CFLAGS) -c alien.c

crown.o: crown.c
	gcc $(CFLAGS) -c crown.c

pointed_celtic.o: pointed_celtic.c
	gcc $(CFLAGS) -c pointed_celtic.c

more_fractals.o: more_fractals.c
	gcc $(CFLAGS) -c more_fractals.c

clean:
	rm -f *.o





