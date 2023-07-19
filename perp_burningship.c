#include "fractals.h"


void SIMD_render_perp_burningship(SDL_Renderer* renderer, 
						   int screen_width, int screen_height,
						   FractalData *f, colorf cf)
{	
	int x, y, i, j, k;

	int color[3];
	int color_input[4];
	
	double *escape_time;

	double x_scale = (f->xub - f->xlb) / screen_width;
	double y_scale = (f->yub - f->ylb) / screen_height;

	__m256d _x, _y, _a, _b, _na, _nb, _re, _im;
	__m256d _xlb, _ylb, _x_scale, _y_scale;
	__m256d _escape_time;
	__m256d _two = _mm256_set1_pd(2.0);
	__m256d _minus = _mm256_set1_pd(-0.0);

	_xlb = _mm256_set1_pd(f->xlb);
	_ylb = _mm256_set1_pd(f->ylb);

	_x_scale = _mm256_set1_pd(x_scale);
	_y_scale = _mm256_set1_pd(y_scale);

	for (y = 0; y < screen_height; y++)
	{
		_y = _mm256_set1_pd(y);
		for (x = 0; x < screen_width; x += 4)
		{
			_x = _mm256_set_pd(x+3, x+2, x+1, x);

			_a = _mm256_add_pd(_xlb, _mm256_mul_pd(_x, _x_scale));
			_b = _mm256_add_pd(_ylb, _mm256_mul_pd(_y, _y_scale));

			_re = _a;
			_im = _b;

			int lock[4] = {0, 0, 0, 0};
			int brightness[4] = {0, 0, 0, 0};

			for (i = 0; i < f->iter; i++)
			{

				_na = _mm256_sub_pd(_mm256_mul_pd(_a, _a), _mm256_mul_pd(_b, _b));
				_nb = _mm256_mul_pd(_two, _mm256_mul_pd(_a, _mm256_andnot_pd(_minus, _b)));

				_a = _mm256_add_pd(_na, _re);
				_b = _mm256_add_pd(_nb, _im);

				_escape_time = _mm256_add_pd(_mm256_mul_pd(_a, _a), _mm256_mul_pd(_b, _b));
				escape_time = (double*)&_escape_time;

				for (j = 0; j < 4; j++)
				{
					if (escape_time[j] > 4 && lock[j] == 0)
					{
						lock[j] = 1;
						color_input[j] = i;
						brightness[j] = 1;
					}
				}

				if (lock[0] == 1 && lock[1] == 1 && lock[2] == 1 && lock[3] == 1) { break; }
			}
			
			for (k = 0; k < 4; k++)
			{
				cf(color, color_input[k], brightness[k]);
				SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
				SDL_RenderDrawPoint(renderer, x+k, y);
			}
		}
	}	
}

/*
void render_mandelbrot_set(SDL_Renderer* renderer, 
						   int screen_width, int screen_height,
						   FractalData *f, colorf cf)
{	
	//double hue;
	int color[3];
	int x, y, i;

	double a, b, na, nb, re, im;

	double x_scale = (f->xub - f->xlb) / screen_width;
	double y_scale = (f->yub - f->ylb) / screen_height;

	for (y = 0; y < screen_height; y++)
	{
		for (x = 0; x < screen_width; x++)
		{
			a = f->xlb + x * x_scale;
			b = f->ylb + y * y_scale;

			re = a;
			im = b;

			i = 0;
			while (i < f->iter)
			{
				na = a*a - b*b;
				nb = 2*a*b;

				a = na + re;
			    b = nb + im;

				if (a*a + b*b > 4) break;

				i++;
			}

			//cf(f, color, i);
			SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}	
}
*/

