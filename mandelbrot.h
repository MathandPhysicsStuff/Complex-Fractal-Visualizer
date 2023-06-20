#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdio.h>
#include "SDL2/SDL.h"
#include "fractal_struct.h"
#include "map.h"

void render_mandelbrot_set(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f);

#endif
