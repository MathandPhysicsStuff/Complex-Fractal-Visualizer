#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "initalize_free.h"
#include "menu.h"
#include "map.h"
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

	int xp, yp;
	long double x_offset, y_offset;
	long double x_lower_bound = -2;	
	long double x_upper_bound = 2;	
	long double y_lower_bound = -2;	
	long double y_upper_bound = 2;
	long double range = 4;

	SDL_bool left_mouse_hold = SDL_FALSE;
	
    SDL_bool running = SDL_TRUE;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
			const SDL_Point mouse_point = { event.button.x, event.button.y };

            if (event.type == SDL_QUIT)
            {
                running = SDL_FALSE;
				break;
            }

			if (state == MENU)	
			{	
				if (event.type == SDL_MOUSEBUTTONUP)
				{
					if(button_logic(event, mandelbrot_button, mouse_point) == SDL_TRUE) { state = MANDELBROT; }
				}
			}
			else
			{
				if (event.type == SDL_MOUSEBUTTONUP)
				{
					left_mouse_hold = SDL_FALSE;
				}

				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					xp = mouse_point.x;
					yp = mouse_point.y;

					left_mouse_hold = SDL_TRUE;
				}
				
				//Moving around the fractal
				if (left_mouse_hold == SDL_TRUE)
				{

					x_offset = map(xp - mouse_point.x, 0, SCREEN_WIDTH, 0, 4);
					y_offset = map(yp - mouse_point.y, 0, SCREEN_HEIGHT, 0, 4);

					x_lower_bound += x_offset;
					x_upper_bound += x_offset;
					y_lower_bound += y_offset;
					y_upper_bound += y_offset;

					xp = mouse_point.x;
					yp = mouse_point.y;
				}
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
				render_mandelbrot_set(renderer,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				x_lower_bound, x_upper_bound, y_lower_bound, y_upper_bound);
				break;
		}

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
	
	free_memory(window);	
    return 0;
}





















