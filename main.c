#include <stdio.h>
#include "SDL2/SDL.h"
#include "menu.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640

typedef enum States
{
	MENU = 0,
	MANDELBROT = 1
} States;
    
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL2 video failed to initialize: \n", SDL_GetError());
    }
    else
    {
        printf("System is ready to go!\n");
    }

    window = SDL_CreateWindow("Hello SDL", 
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,
                                  -1,
                                  SDL_RENDERER_ACCELERATED);

	States state = MENU;

	SDL_Color button_color = { .r = 64, .g = 64, .b = 64 };
	
	SDL_Rect mandelbrot_button = { .x = 64, .y = 32, .w = 64, .h = 32 };

    SDL_bool running = SDL_TRUE;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = SDL_FALSE;
				break;
            }

			switch (state)
			{	
				case MENU:
					if (event.type == SDL_MOUSEBUTTONDOWN)
					{
						const SDL_Point mouse = { event.button.x, event.button.y };
						if(button_logic(event, mandelbrot_button, mouse) == SDL_TRUE) { state = MANDELBROT; }
					}
					break;
				case MANDELBROT:
					break;
			}
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

		switch (state)
		{
			case MENU:
				menu_color(renderer);
				button_render(renderer, mandelbrot_button, button_color);
				break;
			case MANDELBROT:
				break;
		}

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}





















