#ifndef COLORS_H
#define COLORS_H

#include "SDL2/SDL.h"
#include "fractal_struct.h"

typedef void (*colorf)(FractalData*, int*);

void gray_scale(FractalData *f, int *color);

#endif 
