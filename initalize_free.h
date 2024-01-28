#ifndef INITALIZE_FREE_H
#define INITALIZE_FREE_H

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
	
void initalize();
void free_memory(SDL_Window* window, SDL_Renderer* renderer);

#endif
