#ifndef COLORS_H
#define COLORS_H

#include <math.h>
#include <stdio.h>

#include "SDL2/SDL.h"
#include "fractal_struct.h"

typedef void (*colorf)(FractalData* f, int*, int, int);

void gray_scale(FractalData* f, int *color, int i, int brightness);
void hsv(FractalData* f, int *color, int i, int brightness);

#endif 
