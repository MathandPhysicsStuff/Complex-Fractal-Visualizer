#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "menu.h"

void menu_color(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 8, 8, 8, 255);
	SDL_RenderClear(renderer);
}

void button_render(SDL_Renderer *renderer, SDL_Rect button_rect, SDL_Color button_color)
{
	SDL_Rect button_outline = 
							{
							.x = button_rect.x - 4,
							.y = button_rect.y - 4,
							.w = button_rect.w + 8,
							.h = button_rect.h + 8
							};
						  
	SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
	SDL_RenderFillRect(renderer, &button_outline);


	SDL_SetRenderDrawColor(renderer, button_color.r, button_color.g, button_color.b, 255);
	SDL_RenderFillRect(renderer, &button_rect);
}

SDL_Texture* create_texture(SDL_Renderer* renderer, TTF_Font* font, char text[], SDL_Color text_color)
{
	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text, text_color);
	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	SDL_FreeSurface(text_surface);

	return text_texture;
}

void render_texture(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect button_rect)
{
	SDL_Rect text_rect = 
						{
							.x = button_rect.x + 2,	
							.y = button_rect.y + 2,	
							.w = button_rect.w - 4,	
							.h = button_rect.h - 4,	
						};
	SDL_RenderCopy(renderer, texture, NULL, &text_rect);
}


SDL_bool button_logic(SDL_Event event, SDL_Rect button_rect, SDL_Point mouse)
{
	if (SDL_PointInRect(&mouse, &button_rect))
	{
		return SDL_TRUE;
	}
}



















