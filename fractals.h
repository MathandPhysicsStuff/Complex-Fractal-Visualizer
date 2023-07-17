#ifndef FRACTALS_H
#define FRACTALS_H

#include <stdio.h>
#include <immintrin.h>

#include "SDL2/SDL.h"

#include "fractal_struct.h"
#include "colors.h"

//void render_mandelbrot_set(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_mandelbrot_set(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_mandelbar_set(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_burningship(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

#endif
