#ifndef FRACTALS_H
#define FRACTALS_H

#include <stdio.h>
#include <immintrin.h>

#include "SDL2/SDL.h"

#include "fractal_struct.h"
#include "colors.h"

void render_mandelbrot_set(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);
void SIMD_render_mandelbrot_set(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_julia_set(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_mandelbar_set(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_burningship(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_buffalo(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_celtic(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_perp_burningship(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_sharkfin(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_sockpuppet(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_alien(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_crown(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_pointed_celtic(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_perp_mandelbrot(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_air_ship(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_tail(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_power_drill(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_mallet(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_washing_machine(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_spade(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_backwards_ship(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_ray_gun(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_nail_gun(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_speed_boat(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

void SIMD_render_pitcher(SDL_Renderer *renderer, int screen_width, int screen_height, FractalData *f, colorf cf);

#endif
