#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdio.h>
#include "SDL2/SDL.h"
#include <immintrin.h>

void render_mandelbrot_set(SDL_Renderer *renderer,
						   int SCREEN_WIDTH, int SCREEN_HEIGHT,
						   long double a_lower_bound, long double a_upper_bound,
						   long double b_lower_bound, long double b_upper_bound);



#endif
