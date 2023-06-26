#include <stdio.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "fractal_struct.h"
#include "initalize_free.h"
#include "menu.h"
#include "fractals.h"
#include "map.h"
#include "event_inputs.h"
#include "colors.h"


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
const int HALF_WIDTH = SCREEN_WIDTH / 2;
const int HALF_HEIGHT = SCREEN_HEIGHT / 2;

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

	FractalData f = {
					 .x_point = 0, .y_point = 0,
				     .lxoff = 2,  .uxoff = 2,
				     .lyoff = 2,  .uyoff = 2, 
				     .iter = 256
				    };

	colorf fractal_color = &gray_scale;

	SDL_Rect rect = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1, 1};

	SDL_bool left_mouse_hold = SDL_FALSE;
	
    SDL_bool running = SDL_TRUE;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
			SDL_Point mouse = { event.button.x, event.button.y };

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
					if(event.button.button == SDL_BUTTON_LEFT)
					{
						if(button_logic(event, mandelbrot_button, mouse) == SDL_TRUE) { state = MANDELBROT; }
					}
				}
				break;
			
			case MANDELBROT:
				if (key_events(event, &f) == 0) { state = MENU; }
				mouse_button_events(event, &left_mouse_hold, SCREEN_WIDTH, SCREEN_HEIGHT, &f);
				scrollwheel_events(event, SCREEN_WIDTH, SCREEN_HEIGHT, &f);
				break;
			}
		}
			
		f.xlb = f.x_point - f.lxoff;
		f.xub = f.x_point + f.uxoff;
		f.ylb = f.y_point - f.lyoff;
		f.yub = f.y_point + f.uyoff;
				
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
				render_mandelbrot_set(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);

				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderDrawRect(renderer, &rect);
				break;
		}

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
	
	free_memory(window);	
    return 0;
}





















