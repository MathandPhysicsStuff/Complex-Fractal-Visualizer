#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "initalize_free.h"
#include "menu.h"
#include "mandelbrot.h"

typedef enum States
{
	MENU = 0,
	MANDELBROT,
	BURNINGSHIP 
} States;
    
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

int main()
{
	
	initalize();

	SDL_Texture *mandelbrot_text, *burningship_text;

    window = SDL_CreateWindow("Hello SDL", 
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,
                                  -1,
                                  SDL_RENDERER_ACCELERATED);
	
	TTF_Font* font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 64);
	SDL_Color text_color = { 255, 255, 255 };

	mandelbrot_text = create_texture(renderer, font, "Mandelbrot set", text_color);
	burningship_text = create_texture(renderer, font, "Burning Ship", text_color);

	TTF_CloseFont(font);

	SDL_Color button_color = { .r = 96, .g = 96, .b = 96 };
	
	SDL_Rect mandelbrot_button = { .x = 16, .y = 128, .w = 144, .h = 32 };
	SDL_Rect burningship_button = { .x = 176, .y = 128, .w = 144, .h = 32 };

	States state = MENU;
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
					if (event.type == SDL_MOUSEBUTTONUP)
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
				render_texture(renderer, mandelbrot_text, mandelbrot_button);

				button_render(renderer, burningship_button, button_color);
				render_texture(renderer, burningship_text, burningship_button);

				break;
			case MANDELBROT:
				render_mandelbrot_set(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, -2, 2, -2, 2);
				break;
		}

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
	
	free_memory(window);	
    return 0;
}





















