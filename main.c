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

	int xp, yp;
	int m0, m1;
	long double x_map, y_map;
	long double x_mouse, y_mouse;
	long double x_point = 0, y_point = 0;
	long double lx_offset = 2, ux_offset = 2;
	long double ly_offset = 2, uy_offset = 2;
	long double x_lower_bound;	
	long double x_upper_bound;	
	long double y_lower_bound;	
	long double y_upper_bound;

	SDL_Rect rect = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1, 1};

	SDL_bool left_mouse_hold = SDL_FALSE;
	
    SDL_bool running = SDL_TRUE;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
			SDL_Point mouse_point = { event.button.x, event.button.y };

            if (event.type == SDL_QUIT)
            {
                running = SDL_FALSE;
				break;
            }

			if (state == MENU)	
			{	
				if (event.type == SDL_MOUSEBUTTONUP)
				{
					if(event.button.button == SDL_BUTTON_LEFT)
					{
						if(button_logic(event, mandelbrot_button, mouse_point) == SDL_TRUE) { state = MANDELBROT; }
					}
				}
			}

			//I realized everything other than menu will use these keys
			else
			{
				switch (event.type)
				{
					case SDL_KEYDOWN:
						if (event.key.keysym.sym == SDLK_ESCAPE)
						{
							state = MENU;
							x_point = 0, y_point = 0;
							lx_offset = 2, ux_offset = 2;
							ly_offset = 2, uy_offset = 2;
						}
						break;
					case SDL_MOUSEBUTTONUP:
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							left_mouse_hold = SDL_FALSE;
						}
						break;

					case SDL_MOUSEBUTTONDOWN:
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							xp = mouse_point.x;
							yp = mouse_point.y;

							left_mouse_hold = SDL_TRUE;
						}
						break;
				
					//Zooming into the fractal
					case SDL_MOUSEWHEEL:

						//Zooming in
						if (event.wheel.y > 0)
						{
							SDL_GetMouseState(&m0, &m1); 

							x_mouse = fmap(m0, 0, SCREEN_WIDTH, x_lower_bound ,x_upper_bound);
							y_mouse = fmap(m1, 0, SCREEN_HEIGHT, y_lower_bound ,y_upper_bound);
							
							x_point = x_mouse;
							y_point = y_mouse;

							lx_offset = x_point - x_lower_bound;
							ux_offset = x_upper_bound - x_point;
							ly_offset = y_point - y_lower_bound;
							uy_offset = y_upper_bound - y_point;
		
							lx_offset *= 0.8;
							ux_offset *= 0.8;
							ly_offset *= 0.8;
							uy_offset *= 0.8;
						}	
						//Zooming out
						if (event.wheel.y < 0)
						{
							SDL_GetMouseState(&m0, &m1); 

							x_mouse = fmap(m0, 0, SCREEN_WIDTH, x_lower_bound ,x_upper_bound);
							y_mouse = fmap(m1, 0, SCREEN_HEIGHT, y_lower_bound ,y_upper_bound);
							
							x_point = x_mouse;
							y_point = y_mouse;

							lx_offset = x_point - x_lower_bound;
							ux_offset = x_upper_bound - x_point;
							ly_offset = y_point - y_lower_bound;
							uy_offset = y_upper_bound - y_point;
		
							lx_offset *= 1.2;
							ux_offset *= 1.2;
							ly_offset *= 1.2;
							uy_offset *= 1.2;
						}
						break;
				}	
				//Moving around the fractal
				if (left_mouse_hold == SDL_TRUE)
				{
					x_map = fmap(xp - mouse_point.x, 0, SCREEN_WIDTH, 0, x_upper_bound - x_lower_bound);
					y_map = fmap(yp - mouse_point.y, 0, SCREEN_HEIGHT, 0, y_upper_bound - y_lower_bound);
					
					x_point += x_map;	
					y_point += y_map;
						
					xp = mouse_point.x;
					yp = mouse_point.y;
				}
			}
        }
		
		x_lower_bound = x_point - lx_offset;
		x_upper_bound = x_point + ux_offset;
		y_lower_bound = y_point - ly_offset;
		y_upper_bound = y_point + uy_offset;
				
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





















