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

