#ifndef EVENT_INPUTS_H 
#define EVENT_INPUTS_H

#include <stdio.h>
#include "SDL2/SDL.h"
#include "map.h"

int key_events(SDL_Event event,
			   long double *x_point, long double *y_point,
			   long double *lx_offset, long double *ux_offset,
			   long double *ly_offset, long double *uy_offset);


#endif
