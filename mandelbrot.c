#include "fractals.h"

void render_mandelbrot_set(SDL_Renderer* renderer, int screen_width, int screen_height, FractalData *f, colorf cf)
{	
	double hue;
	int color[3];
	
	for (int x = 0; x < screen_width; x++)
	{
		for (int y = 0; y < screen_height; y++)
		{
			f->a = f->xlb + x * (f->xub - f->xlb) / screen_width;
			f->b = f->ylb + y * (f->yub - f->ylb) / screen_height;

			f->rp = f->a;
			f->ip = f->b;
			
			cf(f, color);
			SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}	
}












