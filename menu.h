#ifndef MENU_H
#define MENU_H

void menu_color(SDL_Renderer *renderer);
void button_render(SDL_Renderer *renderer, SDL_Rect button_rect, SDL_Color button_color);
SDL_bool button_logic(SDL_Event event, SDL_Rect button_rect, SDL_Point mouse);

#endif
