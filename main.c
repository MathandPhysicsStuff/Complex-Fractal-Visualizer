#include <stdio.h>
#include <time.h>

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

	SDL_Texture *fractals_text, *colors_text;
	SDL_Texture *mandelbrot_text, *burningship_text, *tricorn_text;
	SDL_Texture *gray_scale_text, *hsb_text;

	window = SDL_CreateWindow("Hello SDL", 
							  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							  SCREEN_WIDTH, SCREEN_HEIGHT,
							  SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window,
								  -1,
								  SDL_RENDERER_ACCELERATED);

	TTF_Font* font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 64);
	TTF_Font* font2 = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
	SDL_Color text_color = { 220, 220, 220 };
	SDL_Color timespec_text_color = { 0, 255, 0 };

	//Titles
	fractals_text = create_texture(renderer, font, "Fractals", text_color);
	colors_text = create_texture(renderer, font, "Colors", text_color);
	
	//Fractals text
	mandelbrot_text = create_texture(renderer, font, "Mandelbrot Set", text_color);
	burningship_text = create_texture(renderer, font, "Burning Ship", text_color);
	tricorn_text = create_texture(renderer, font, "Mandelbar Set", text_color);

	//Colors text
	gray_scale_text = create_texture(renderer, font, "Gray Scale", text_color);
	hsb_text = create_texture(renderer, font2, "HSB", text_color);

	TTF_CloseFont(font);
	TTF_CloseFont(font2);

	SDL_Color button_color = { .r = 96, .g = 96, .b = 96 };

	//Titles buttons rects
	SDL_Rect fractals_button = { .x = 152, .y = 16, .w = 176, .h = 64 };
	SDL_Rect colors_button = { .x = 496, .y = 32, .w = 128, .h = 42 };
	
	//fractal button rects	
	SDL_Rect mandelbrot_button = { .x = 24, .y = 96, .w = 128, .h = 32 };
	SDL_Rect burningship_button = { .x = 176, .y = 96, .w = 128, .h = 32 };
	SDL_Rect tricorn_button = { .x = 328, .y = 96, .w = 136, .h = 32 };

	//color button rects
	SDL_Rect gray_scale_button = { .x = 504, .y = 96, .w = 112, .h = 32 };
	SDL_Rect hsb_button = { .x = 504, .y = 144, .w = 112, .h = 32 };

	States state = MENU;

	FractalData f = {
					 .x_point = 0, .y_point = 0,
				     .lxoff = 2,  .uxoff = 2,
				     .lyoff = 2,  .uyoff = 2, 
				     .iter = 256
				    };

	colorf fractal_color = &gray_scale;

	SDL_bool left_mouse_hold = SDL_FALSE;
	
    SDL_bool running = SDL_TRUE;
	
	//benchmarking code on linux
	struct timespec begin;
	struct timespec end;
	double time_spent;
	char time_spent_str[20];

	SDL_Rect timespec_button = { .x = 20, .y = 20, .w = 64, .h = 24 };
	SDL_Texture* timespec_text;	
	TTF_Font* timespec_font;

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

						if(button_logic(event, gray_scale_button, mouse) == SDL_TRUE) { fractal_color = &gray_scale; }
						else if(button_logic(event, hsb_button, mouse) == SDL_TRUE) { fractal_color = &hsv; }
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

				SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);
				SDL_RenderDrawLine(renderer, 484, 0, 484, 640);

				render_texture(renderer, fractals_text, fractals_button);
				render_texture(renderer, colors_text, colors_button);

				button_render(renderer, mandelbrot_button, button_color);
				render_texture(renderer, mandelbrot_text, mandelbrot_button);

				button_render(renderer, burningship_button, button_color);
				render_texture(renderer, burningship_text, burningship_button);

				button_render(renderer, tricorn_button, button_color);
				render_texture(renderer, tricorn_text, tricorn_button);

				button_render(renderer, gray_scale_button, button_color);
				render_texture(renderer, gray_scale_text, gray_scale_button);

				button_render(renderer, hsb_button, button_color);
				render_texture(renderer, hsb_text, hsb_button);
				break;

			case MANDELBROT:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);

				render_mandelbrot_set(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);

				timespec_get(&end, TIME_UTC);

				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);

				render_texture(renderer, timespec_text, timespec_button);

				break;
		}

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
	
	free_memory(window);	
    return 0;
}





















