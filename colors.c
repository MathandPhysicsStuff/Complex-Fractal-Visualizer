#include "colors.h"

void gray_scale(FractalData *f, int *color)
{
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
}

void hsv(FractalData *f, int *color)
{
	double r, g, b; //red green blue
	double h, s, v; //hue saturation value
	double c, x, m;

	for (int i = 0; i < f->iter; i++)
	{
		f->na = f->a * f->a - f->b * f->b;
		f->nb = 2 * f->a * f->b;

		f->a = f->na + f->rp;
		f->b = f->nb + f->ip;

		if (f->a * f->a + f->b * f->b > 4)
		{
			h = i%359;
			v = 1 - (i / f->iter);
			s = 1 - (i / f->iter);
			
			c = s*v;
			x = c*(1 - fabs(fmod(h/60, 2) - 1));
			m = v - c;

			if (0 <= h && h < 60){r = c, g = x, b = 0;}
			else if (60 <= h && h < 120){r = x, g = c, b = 0;}
			else if (120 <= h && h < 180){r = 0, g = c, b = x;}
			else if (180 <= h && h < 240){r = 0, g = x, b = c;}
			else if (240 <= h && h < 300){r = x, g = 0, b = c;}
			else if (300 <= h && h < 360){r = c, g = 0, b = x;}
			
			color[0] = (r+m)*255;
			color[1] = (g+m)*255;
			color[2] = (b+m)*255;

			break;
		 }
		 else
		 {
			color[0] = 0;
			color[1] = 0;
			color[2] = 0;
		 }

	}
}






















