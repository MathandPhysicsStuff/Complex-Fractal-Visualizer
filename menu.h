#ifndef MENU_H
#define MENU_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

void menu_color(SDL_Renderer *renderer);

void button_render(SDL_Renderer *renderer, SDL_Rect button_rect, SDL_Color button_color);

SDL_Texture* create_texture(SDL_Renderer* renderer, TTF_Font* font, char text[], SDL_Color);

void render_texture(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect button_rect);

SDL_bool button_logic(SDL_Event event, SDL_Rect button_rect, SDL_Point mouse);

#endif
