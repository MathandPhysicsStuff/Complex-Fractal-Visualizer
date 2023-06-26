#include "event_inputs.h"


int key_events(SDL_Event event, FractalData *f)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_ESCAPE:
				f->x_point = 0, f->y_point = 0;
				f->lxoff = 2, f->uxoff = 2;
				f->lyoff = 2, f->uyoff = 2;
				f->iter = 64;
				return 0;	
				break;

			case SDLK_i:
				f->iter += 64;
				break;

			case SDLK_o:
				if (f->iter > 64) 
				{
					f->iter -= 64;
				}
				break;

			case SDLK_z:
				f->lxoff *= 0.8;
				f->uxoff *= 0.8;
				f->lyoff *= 0.8;
				f->uyoff *= 0.8;
				break;

			case SDLK_x:
				f->lxoff *= 1.2;
				f->uxoff *= 1.2;
				f->lyoff *= 1.2;
				f->uyoff *= 1.2;
				break;
		}
	}
}

void mouse_button_events(SDL_Event event, SDL_bool *holdm, int screen_width, int screen_height, FractalData *f)
{
	SDL_Point mouse = {event.button.x, event.button.y};
	
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			*holdm = SDL_FALSE;
		}
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			f->x_mp = mouse.x; 
			f->y_mp = mouse.y; 

			*holdm = SDL_TRUE;
		}
	}

	if (*holdm == SDL_TRUE)
	{
		f->fx_mp = 0 + (f->x_mp - mouse.x) * ((f->xub - f->xlb) / screen_width); 	
		f->fy_mp = 0 + (f->y_mp - mouse.y) * ((f->yub - f->ylb) / screen_height); 	

		f->x_point += f->fx_mp;
		f->y_point += f->fy_mp;

		f->x_mp = mouse.x; 
		f->y_mp = mouse.y; 
	}
}

void scrollwheel_events(SDL_Event event, int screen_width, int screen_height, FractalData *f)
{
	int x_mouse, y_mouse;
	if (event.type == SDL_MOUSEWHEEL)
	{
		SDL_GetMouseState(&x_mouse, &y_mouse);

		f->fx_mp = f->xlb + x_mouse * (f->xub - f->xlb) / screen_width;
		f->fy_mp = f->ylb + y_mouse * (f->yub - f->ylb) / screen_height;

		f->x_point = f->fx_mp;
		f->y_point = f->fy_mp;

		f->lxoff = f->x_point - f->xlb;
		f->uxoff = f->xub - f->x_point;
		f->lyoff = f->y_point - f->ylb;
		f->uyoff = f->yub - f->y_point;

		if (event.wheel.y > 0)
		{
			f->lxoff *= 0.8;
			f->uxoff *= 0.8;
			f->lyoff *= 0.8;
			f->uyoff *= 0.8;
		}
		else if (event.wheel.y < 0)
		{
			f->lxoff *= 1.2;
			f->uxoff *= 1.2;
			f->lyoff *= 1.2;
			f->uyoff *= 1.2;
		}
	}
}





