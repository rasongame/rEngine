//#include "../Logger/Logger.hpp"
#include <SDL2/SDL.h>
class Rectangle {
	public:
		Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h);

        Rectangle() {};
		int x, y, w, h;
		void Render(int newX, int newY);
		SDL_Renderer *renderer;
		SDL_Rect rect;

};
