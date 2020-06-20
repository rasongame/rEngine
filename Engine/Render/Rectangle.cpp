#include "Rectangle.hpp"

Rectangle::Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->renderer = renderer;
	SDL_Rect rect = {x,y,w,h};
	this->rect = rect;

}
void Rectangle::Render(int newX, int newY) {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	this->rect.y = newY;
	this->rect.x = newX;
	SDL_RenderDrawRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0 );
}
