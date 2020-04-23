#ifndef GAME_HPP
#define GAME_HPP
extern "C" {
	#include <SDL2/SDL.h>
}
#pragma once
#include <iostream>
#include "../Logger/Logger.hpp"
#include "../Render/Triangle.hpp"
#include "../Render/pseudo3dcube.hpp"
#include "../Render/pseudo3dtriangle.hpp"
struct Mouse {
	int x = 0 , y = 0;
};

class Game
{
public:
	Game();
	Logger logger;
    void changeTitle(std::string title) {
        SDL_SetWindowTitle(window,title.c_str());
    };
	void update();
	void render();
	std::string title;
    int width = 800;
    int height = 600;
    ~Game();
private:
	SDL_Texture *textures[4];
	SDL_Window *window;
	SDL_Surface *surface;
	SDL_Renderer *renderer;
	Mouse mouse{0,0};
};

#endif // GAME_HPP
