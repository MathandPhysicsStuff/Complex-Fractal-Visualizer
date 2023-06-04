#include <stdio.h>
#include "SDL2/SDL.h"
#include "menu.h"


void menu_color(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 8, 8, 16, 255);
	SDL_RenderClear(renderer);
}

void button_render(SDL_Renderer *renderer, SDL_Rect button_rect, SDL_Color button_color)
{
	SDL_Rect button_outline = {
						  .x = button_rect.x - 2,
						  .y = button_rect.y - 2,
						  .w = button_rect.w + 4,
						  .h = button_rect.h + 4
						};
						  
	SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
	SDL_RenderFillRect(renderer, &button_outline);


	SDL_SetRenderDrawColor(renderer, button_color.r, button_color.g, button_color.b, 255);
	SDL_RenderFillRect(renderer, &button_rect);
}

SDL_bool button_logic()
{

}



















