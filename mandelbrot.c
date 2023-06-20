#include "mandelbrot.h"
#include "map.h"


void render_mandelbrot_set(SDL_Renderer* renderer, int screen_width, int screen_height, FractalData *f)
{	
	double hue;
	int color[3];
	
	for (int x = 0; x < screen_width; x++)
	{
		for (int y = 0; y < screen_height; y++)
		{
			//mapping
			f->a = f->xlb + x * (f->xub - f->xlb) / screen_width;
			f->b = f->ylb + y * (f->yub - f->ylb) / screen_height;

			f->rp = f->a;
			f->ip = f->b;

			for (int i = 0; i < f->iter; i++)
			{
				f->na = f->a * f->a - f->b * f->b;
				f->nb = 2 * f->a * f->b;

				f->a = f->na + f->rp;
				f->b = f->nb + f->ip;
			
				if (f->a * f->a + f->b * f->b > 4)
				{
					color[0] = i%256;	
					color[1] = i%256;	
					color[2] = i%256;
					break; 
				}
				else
				{
					color[0] = 0;	
					color[1] = 0;	
					color[2] = 0;	
				}
			}   
		 	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}	
}

/*
void render_mandelbrot_set(SDL_Renderer* renderer,
						   int SCREEN_WIDTH, int SCREEN_HEIGHT,
						   long double a_lower_bound, long double a_upper_bound,
						   long double b_lower_bound, long double b_upper_bound)
						   
{	
	long double a, b;
	long double next_a, next_b;
	long double real_position, imaginary_position;
	double hue;
	int color[3];
	
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			a = map(x, 0, SCREEN_WIDTH, a_lower_bound, a_upper_bound);
			b = map(y, 0, SCREEN_HEIGHT, b_lower_bound, b_upper_bound);

			real_position = a;
			imaginary_position = b;

			for (int i = 0; i < 256; i++)
			{
				next_a = a*a - b*b;
				next_b = 2*a*b;

				a = next_a + real_position;
				b = next_b + imaginary_position;

				if (a*a + b*b > 4)
				{
					color[0] = i%256;	
					color[1] = i%256;	
					color[2] = i%256;
					break; 
				}
				else
				{
					color[0] = 0;	
					color[1] = 0;	
					color[2] = 0;	
				}
			}   
		 	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}	
}
*/


















