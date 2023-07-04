#ifndef COLORS_H
#define COLORS_H

#include <math.h>
#include <stdio.h>

#include "SDL2/SDL.h"
#include "fractal_struct.h"

typedef void (*colorf)(int*, int, int);

void gray_scale(int *color, int i, int brightness);
void hsv(int *color, int i, int brightness);

#endif 
