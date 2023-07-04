#ifndef EVENT_INPUTS_H 
#define EVENT_INPUTS_H

#include <stdio.h>
#include "SDL2/SDL.h"
#include "fractal_struct.h"

int key_events(SDL_Event event, FractalData *f);
void mouse_button_events(SDL_Event event, SDL_bool *holdm, int screen_width, int screen_height, FractalData *f);
void scrollwheel_events(SDL_Event event, int screen_width, int screen_height, FractalData *f);

#endif
