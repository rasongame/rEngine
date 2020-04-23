#include "game.hpp"
#include <SDL2/SDL_image.h>
#include <random>
#include <filesystem>

void handleScroll(SDL_Event event) {
    if (event.wheel.y > 0) {
        Logger().printInfo(std::to_string(event.wheel.y));
    } else if (event.wheel.y < 0) {
        Logger().printInfo(std::to_string(event.wheel.y));
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
        }
    }
}
Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(0);
    return;
}

