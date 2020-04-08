#ifndef GAME_HPP
#define GAME_HPP
extern "C" {
	#include <SDL2/SDL.h>
}
#include <iostream>
#include "../Logger/Logger.hpp"

struct Mouse {
	int x = 0 , y = 0;
};

class Game
{
public:
	Game();
	Logger logger;
	void update();
	void render();
	std::string title;
	int width = 640;
	int height = 480;

	~Game();
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *surface;
	Mouse mouse{0,0};
};

#endif // GAME_HPP
