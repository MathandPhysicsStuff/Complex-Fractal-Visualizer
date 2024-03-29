#include "initalize_free.h"

void initalize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL2 video failed to initialize: \n", SDL_GetError());
	}
	else
	{
		printf("System is ready to go!\n");
	}
	if (TTF_Init() == -1)
	{
		printf("Could not initalize SDL2_ttf, error:\n", TTF_GetError());
	}
	else 
	{
		printf("SDL2_ttf system is ready to go\n");
	}
}

void free_memory(SDL_Window* window, SDL_Renderer* renderer)
{
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
