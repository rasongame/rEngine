#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include <iostream>
#include "../Logger/Logger.hpp"
#include "../Render/Triangle.hpp"
#include "../Render/pseudo3dcube.hpp"
#include "../Render/pseudo3dtriangle.hpp"
#include "../Render/RenderUtils.hpp"
#include "settings.hpp"
struct Pos {
	int x = 0 , y = 0;
};

class Game
{
public:
	Game();
    void changeTitle(std::string title) {
        SDL_SetWindowTitle(window,title.c_str());
    };
	void update();
	void render();
	std::string title;
    int width = WIDTH;
    int height = HEIGHT;
	SDL_Renderer *renderer;
	int player_speed = 10;
	Rectangle *player;
	Pos mouse{0,0};
	Pos player_pos{0,0};
	Rectangle *mouse_rect;

    ~Game();
	void handleKeyboard(SDL_Event event);
private:
    SDL_Texture *textures[TEXTURE_COUNT];
	SDL_Window *window;
	SDL_Surface *surface;
};

#endif // GAME_HPP
