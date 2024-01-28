#include <stdio.h>
#include <time.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "fractal_struct.h"
#include "initalize_free.h"
#include "menu.h"
#include "fractals.h"
#include "event_inputs.h"
#include "colors.h"


typedef enum States
{
	MENU = 0,
	MANDELBROT,
	JULIA,
	MANDELBAR,
	BURNINGSHIP,
	BUFFALO,
	CELTIC,
	PERPBURNINGSHIP,
	SHARKFIN,
	SOCKPUPPET,
	ALIEN,
	CROWN,
	POINTEDCELTIC,
    PERPMANDELBROT,
    AIRSHIP,
    TAIL,
    POWERDRILL,
    MALLET,
    WASHINGMACHINE,
    SPADE,
    BACKWARDSSHIP,
    RAYGUN,
    NAILGUN,
    SPEEDBOAT,
    PITCHER,
	TESTFRACTAL 
} States;

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

const int SCREEN_WIDTH = 1280; //640; //405; 
const int SCREEN_HEIGHT = 720; //576;
const int HALF_WIDTH = SCREEN_WIDTH / 2;
const int HALF_HEIGHT = SCREEN_HEIGHT / 2;

int main()
{

	initalize();

	SDL_Texture *fractals_text, *colors_text;

	SDL_Texture *mandelbrot_text, *julia_text, *burningship_text, *tricorn_text, *buffalo_text, *celtic_text;
	SDL_Texture *perp_burningship_text, *sharkfin_text, *sockpuppet_text, *alien_text, *crown_text, *pointed_celtic_text;
	SDL_Texture *perp_mandelbrot_text, *air_ship_text, *tail_text, *power_drill_text, *mallet_text, *washing_machine_text;
	SDL_Texture *spade_text, *backwards_ship_text, *ray_gun_text, *nail_gun_text, *speed_boat_text, *pitcher_text;

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
	julia_text = create_texture(renderer, font, "Julia Set", text_color);
	burningship_text = create_texture(renderer, font, "Burning Ship", text_color);
	tricorn_text = create_texture(renderer, font, "Mandelbar Set", text_color);
	buffalo_text = create_texture(renderer, font, "Buffalo Fractal", text_color);
	celtic_text = create_texture(renderer, font, "Celtic Fractal", text_color);
	perp_burningship_text = create_texture(renderer, font, "Perp Burning Ship", text_color);
	sharkfin_text = create_texture(renderer, font, "Shark Fin", text_color);
	sockpuppet_text = create_texture(renderer, font, "Sock Puppet", text_color);
	alien_text = create_texture(renderer, font, "Alien Fractal", text_color);
	crown_text = create_texture(renderer, font, "Crown Fractal", text_color);
	pointed_celtic_text = create_texture(renderer, font, "Pointed Celtic", text_color);
	perp_mandelbrot_text = create_texture(renderer, font, "Perp Mandelbrot", text_color);
	air_ship_text = create_texture(renderer, font, "Air Ship", text_color);
	tail_text = create_texture(renderer, font, "Tail Fractal", text_color);
	power_drill_text = create_texture(renderer, font, "Power Drill", text_color);
	mallet_text = create_texture(renderer, font, "Mallet Fractal", text_color);
	washing_machine_text = create_texture(renderer, font, "washing machine", text_color);
	spade_text = create_texture(renderer, font, "Spade Fractal", text_color);
	backwards_ship_text = create_texture(renderer, font, "Backwards Ship", text_color);
	ray_gun_text = create_texture(renderer, font, "Ray Gun", text_color);
	nail_gun_text = create_texture(renderer, font, "Nail Gun", text_color);
	speed_boat_text = create_texture(renderer, font, "Speed Boat", text_color);
	pitcher_text = create_texture(renderer, font, "Pitcher Fractal", text_color);
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
	SDL_Rect julia_button = { .x = 24, .y = 144, .w = 128, .h = 32 };
	SDL_Rect crown_button = { .x = 24, .y = 192, .w = 128, .h = 32 };
	SDL_Rect alien_button = { .x = 24, .y = 240, .w = 128, .h = 32 };
	SDL_Rect perp_mandelbrot_button = { .x = 24, .y = 296, .w = 128, .h = 32 };
	SDL_Rect air_ship_button = { .x = 24, .y = 344, .w = 128, .h = 32 };
	SDL_Rect tail_button = { .x = 24, .y = 392, .w = 128, .h = 32 };
	SDL_Rect power_drill_button = { .x = 24, .y = 440, .w = 128, .h = 32 };

	SDL_Rect burningship_button = { .x = 176, .y = 96, .w = 128, .h = 32 };
	SDL_Rect buffalo_button = { .x = 176, .y = 144, .w = 128, .h = 32 };
	SDL_Rect perp_burningship_button = { .x = 176, .y = 192, .w = 128, .h = 32 };
	SDL_Rect sharkfin_button = { .x = 176, .y = 240, .w = 128, .h = 32 };
	SDL_Rect mallet_button = { .x = 176, .y = 296, .w = 128, .h = 32 };
	SDL_Rect washing_machine_button = { .x = 176, .y = 344, .w = 128, .h = 32 };
	SDL_Rect spade_button = { .x = 176, .y = 392, .w = 128, .h = 32 };
	SDL_Rect backwards_ship_button = { .x = 176, .y = 440, .w = 128, .h = 32 };


	SDL_Rect tricorn_button = { .x = 328, .y = 96, .w = 136, .h = 32 };
	SDL_Rect celtic_button = { .x = 328, .y = 144, .w = 136, .h = 32 };
	SDL_Rect pointed_celtic_button = { .x = 328, .y = 196, .w = 136, .h = 32 };
	SDL_Rect sockpuppet_button = { .x = 328, .y = 240, .w = 136, .h = 32 };
	SDL_Rect ray_gun_button = { .x = 328, .y = 296, .w = 128, .h = 32 };
	SDL_Rect nail_gun_button = { .x = 328, .y = 344, .w = 128, .h = 32 };
	SDL_Rect speed_boat_button = { .x = 328, .y = 392, .w = 128, .h = 32 };
	SDL_Rect pitcher_button = { .x = 328, .y = 440, .w = 128, .h = 32 };

	//color button rects
	SDL_Rect gray_scale_button = { .x = 504, .y = 96, .w = 112, .h = 32 };
	SDL_Rect hsb_button = { .x = 504, .y = 144, .w = 112, .h = 32 };
	SDL_Rect highlight_button = { .x = 504, .y = 96, .w = 112, .h = 32 };

	States state = MENU;

	FractalData f = {
					 .x_point = 0, .y_point = 0,
				     .lxoff = 2,  .uxoff = 2,
				     .lyoff = 2,  .uyoff = 2,
					 .re = 0, .im = 0,
				     .iter = 256 
				    };

	colorf fractal_color = &gray_scale;
	//colorf fractal_color = &hsv;

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
			
			if (state == MENU)
			{
				if (event.type == SDL_MOUSEBUTTONUP)
				{
					if(event.button.button == SDL_BUTTON_LEFT)
					{
						if(button_logic(event, mandelbrot_button, mouse) == SDL_TRUE) { state = MANDELBROT; }
						if(button_logic(event, tricorn_button, mouse) == SDL_TRUE) { state = MANDELBAR; }
						if(button_logic(event, burningship_button, mouse) == SDL_TRUE) { state = BURNINGSHIP; }
						if(button_logic(event, julia_button, mouse) == SDL_TRUE) { state = JULIA; }
						if(button_logic(event, buffalo_button, mouse) == SDL_TRUE) { state = BUFFALO; }
						if(button_logic(event, celtic_button, mouse) == SDL_TRUE) { state = CELTIC; }
						if(button_logic(event, perp_burningship_button, mouse) == SDL_TRUE) { state = PERPBURNINGSHIP; }
						if(button_logic(event, sharkfin_button, mouse) == SDL_TRUE) { state = SHARKFIN; }
						if(button_logic(event, sockpuppet_button, mouse) == SDL_TRUE) { state = SOCKPUPPET; }
						if(button_logic(event, alien_button, mouse) == SDL_TRUE) { state = ALIEN; }
						if(button_logic(event, crown_button, mouse) == SDL_TRUE) { state = CROWN; }
						if(button_logic(event, pointed_celtic_button, mouse) == SDL_TRUE) { state = POINTEDCELTIC; }
						if(button_logic(event, perp_mandelbrot_button, mouse) == SDL_TRUE) { state = PERPMANDELBROT; }
						if(button_logic(event, air_ship_button, mouse) == SDL_TRUE) { state = AIRSHIP; }
						if(button_logic(event, tail_button, mouse) == SDL_TRUE) { state = TAIL; }
						if(button_logic(event, power_drill_button, mouse) == SDL_TRUE) { state = POWERDRILL; }
						if(button_logic(event, mallet_button, mouse) == SDL_TRUE) { state = MALLET; }
						if(button_logic(event, washing_machine_button, mouse) == SDL_TRUE) { state = WASHINGMACHINE; }
						if(button_logic(event, spade_button, mouse) == SDL_TRUE) { state = SPADE; }
						if(button_logic(event, backwards_ship_button, mouse) == SDL_TRUE) { state = BACKWARDSSHIP; }
						if(button_logic(event, ray_gun_button, mouse) == SDL_TRUE) { state = RAYGUN; }
						if(button_logic(event, nail_gun_button, mouse) == SDL_TRUE) { state = NAILGUN; }
						if(button_logic(event, speed_boat_button, mouse) == SDL_TRUE) { state = SPEEDBOAT; }
						if(button_logic(event, pitcher_button, mouse) == SDL_TRUE) { state = PITCHER; }


						if(button_logic(event, gray_scale_button, mouse) == SDL_TRUE)
						{ 
							fractal_color = &gray_scale;
							highlight_button.y = gray_scale_button.y;
						}
						else if(button_logic(event, hsb_button, mouse) == SDL_TRUE)
						{ 
							fractal_color = &hsv;
							highlight_button.y = hsb_button.y;
						}
					}
				}
			}
			
			else
			{
				if (key_events(event, &f) == 0) { state = MENU; }
				mouse_button_events(event, &left_mouse_hold, SCREEN_WIDTH, SCREEN_HEIGHT, &f);
				scrollwheel_events(event, SCREEN_WIDTH, SCREEN_HEIGHT, &f);
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
				
				//Fractal buttons
				button_render(renderer, mandelbrot_button, button_color);
				render_texture(renderer, mandelbrot_text, mandelbrot_button);

				button_render(renderer, julia_button, button_color);
				render_texture(renderer, julia_text, julia_button);

				button_render(renderer, burningship_button, button_color);
				render_texture(renderer, burningship_text, burningship_button);

				button_render(renderer, tricorn_button, button_color);
				render_texture(renderer, tricorn_text, tricorn_button);

				button_render(renderer, buffalo_button, button_color);
				render_texture(renderer, buffalo_text, buffalo_button);

				button_render(renderer, celtic_button, button_color);
				render_texture(renderer, celtic_text, celtic_button);
	
				button_render(renderer, perp_burningship_button, button_color);
				render_texture(renderer, perp_burningship_text, perp_burningship_button);
	
				button_render(renderer, sharkfin_button, button_color);
				render_texture(renderer, sharkfin_text, sharkfin_button);
	
				button_render(renderer, sockpuppet_button, button_color);
				render_texture(renderer, sockpuppet_text, sockpuppet_button);
	
				button_render(renderer, alien_button, button_color);
				render_texture(renderer, alien_text, alien_button);
	
				button_render(renderer, crown_button, button_color);
				render_texture(renderer, crown_text, crown_button);
	
				button_render(renderer, pointed_celtic_button, button_color);
				render_texture(renderer, pointed_celtic_text, pointed_celtic_button);

				button_render(renderer, perp_mandelbrot_button, button_color);
				render_texture(renderer, perp_mandelbrot_text, perp_mandelbrot_button);

				button_render(renderer, air_ship_button, button_color);
				render_texture(renderer, air_ship_text, air_ship_button);

				button_render(renderer, tail_button, button_color);
				render_texture(renderer, tail_text, tail_button);

				button_render(renderer, power_drill_button, button_color);
				render_texture(renderer, power_drill_text, power_drill_button);

				button_render(renderer, mallet_button, button_color);
				render_texture(renderer, mallet_text, mallet_button);

				button_render(renderer, washing_machine_button, button_color);
				render_texture(renderer, washing_machine_text, washing_machine_button);

				button_render(renderer, spade_button, button_color);
				render_texture(renderer, spade_text, spade_button);
	
				button_render(renderer, backwards_ship_button, button_color);
				render_texture(renderer, backwards_ship_text, backwards_ship_button);
	
				button_render(renderer, ray_gun_button, button_color);
				render_texture(renderer, ray_gun_text, ray_gun_button);
				
				button_render(renderer, nail_gun_button, button_color);
				render_texture(renderer, nail_gun_text, nail_gun_button);
				
				button_render(renderer, speed_boat_button, button_color);
				render_texture(renderer, speed_boat_text, speed_boat_button);
				
				button_render(renderer, pitcher_button, button_color);
				render_texture(renderer, pitcher_text, pitcher_button);
 

				//Color buttons
				button_render(renderer, gray_scale_button, button_color);
				button_render(renderer, hsb_button, button_color);

				SDL_SetRenderDrawColor(renderer, 200, 32, 32, 255);
				SDL_RenderFillRect(renderer, &highlight_button);

				render_texture(renderer, gray_scale_text, gray_scale_button);
				render_texture(renderer, hsb_text, hsb_button);

				break;

			case MANDELBROT:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				//render_mandelbrot_set(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
				SIMD_render_mandelbrot_set(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;

			case MANDELBAR:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_mandelbar_set(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;

			case BURNINGSHIP:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_burningship(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;

			case JULIA:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_julia_set(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;

			case BUFFALO:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_buffalo(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;

			case CELTIC:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_celtic(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;

			case PERPBURNINGSHIP:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_perp_burningship(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case SHARKFIN:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_sharkfin(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case SOCKPUPPET:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_sockpuppet(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case ALIEN:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_alien(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case CROWN:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_crown(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case POINTEDCELTIC:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_pointed_celtic(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;

			case PERPMANDELBROT:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_perp_mandelbrot(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;

			case AIRSHIP:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_air_ship(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case TAIL:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_tail(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case POWERDRILL:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_power_drill(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case MALLET:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_mallet(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case WASHINGMACHINE:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_washing_machine(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case SPADE:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_spade(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case BACKWARDSSHIP:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_backwards_ship(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case RAYGUN:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_ray_gun(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case NAILGUN:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_nail_gun(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;


			case SPEEDBOAT:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_speed_boat(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;

			case PITCHER:

				timespec_font = TTF_OpenFont("DejaVuMathTeXGyre.ttf", 48);
				timespec_get(&begin, TIME_UTC);
				
				SIMD_render_pitcher(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &f, fractal_color);
			
				timespec_get(&end, TIME_UTC);
				time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
				sprintf(time_spent_str, "%f", time_spent);

				timespec_text = create_texture(renderer, timespec_font, time_spent_str, timespec_text_color);
				TTF_CloseFont(timespec_font);
				//render_texture(renderer, timespec_text, timespec_button);

				break;




		}

        SDL_RenderPresent(renderer);
        //SDL_Delay(1);
    }
	
	free_memory(window, renderer);	
    return 0;
}





















