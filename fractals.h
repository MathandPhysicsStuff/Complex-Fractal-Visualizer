#ifndef FRACTALS_H
#define FRACTALS_H

#include <stdio.h>
#include "SDL2/SDL.h"
#include "fractal_struct.h"
#include "colors.h"
#include "map.h"

void render_mandelbrot_set(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

#endif
