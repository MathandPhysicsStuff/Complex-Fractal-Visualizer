#include <stdio.h>
#include "event_inputs.h"

int key_events(SDL_Event event,
					 long double *x_point, long double *y_point,
					 long double *lx_offset, long double *ux_offset,
					 long double *ly_offset, long double *uy_offset)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_ESCAPE:
				*x_point = 0, *y_point = 0;
				*lx_offset = 2, *ux_offset = 2;
				*ly_offset = 2, *uy_offset = 2;
				return 0;	
				break;
		}
	}
}



