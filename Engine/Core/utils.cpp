
#include "game.hpp"

#include <SDL2/SDL_image.h>
#include <random>
#include <filesystem>

void handleScroll(SDL_Event event) {
#ifdef LOGGER_SHOW_WALK_DIRECTION
    if (event.wheel.y > 0) {
        Logger::printInfo(std::to_string(event.wheel.y));
    } else if (event.wheel.y < 0) {
        Logger::printInfo(std::to_string(event.wheel.y));
    }
#endif
}
void Game::handleKeyboard(SDL_Event event){
	switch (event.key.keysym.sym) {
		case SDLK_LEFT:
            Logger::printInfo("left");
			this->player->x -= this->player_speed;
		break;
		case SDLK_RIGHT:
            Logger::printInfo("right");
			this->player->x += this->player_speed;
			break;
		case SDLK_UP:
            Logger::printInfo("up");
			this->player->y += this->player_speed;
			break;
		case SDLK_DOWN:
            Logger::printInfo("down");
			this->player->y -= this->player_speed;
			break;

	}

}
void Game::update() {
    SDL_Event event;
	SDL_GetMouseState(&mouse.x, &mouse.y);
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
        case SDL_QUIT:
            this->~Game();
        case SDL_MOUSEWHEEL:
			handleScroll(event);

		case SDL_KEYDOWN:
			handleKeyboard(event);
		}
    }
}
Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_Quit();
    return;
}


