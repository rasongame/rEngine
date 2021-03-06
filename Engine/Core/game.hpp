﻿#ifndef GAME_HPP
#define GAME_HPP

#include <Common/common.hpp>
struct Pos {
	int x = 0 , y = 0;
};

class Game
{
public:
	Game();
	static Game *getInstance();
    static Game* m_instance;
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
