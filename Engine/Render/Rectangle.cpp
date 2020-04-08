#include "Rectangle.hpp"

Rectangle::Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	SDL_Rect rect = {x,y,w,h};
	this->rect = rect;
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0 );
}
