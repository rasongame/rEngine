#include "game.hpp"

#include "../Render/Rectangle.hpp"
Game::Game()
{
	SDL_ShowCursor(SDL_DISABLE);
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	}

	logger.printInfo("Creating renderer and window");
	window = SDL_CreateWindow(title.c_str(), 0,0, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		logger.printError("Window is NULL pointer");
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == nullptr) {
		logger.printError("Renderer is NULL pointer");
	}
	surface = SDL_GetWindowSurface(window);

}
void Game::render() {
	SDL_RenderClear(renderer);
	Rectangle rect(renderer, mouse.x-32, mouse.y-32, 64, 64);
//	logger.printInfo(std::to_string(mouse.x));
//	logger.printInfo(std::to_string(mouse.y));
	SDL_RenderPresent(renderer);
	//	SDL_UpdateWindowSurface(window);
}
void Game::update() {
	SDL_Event event;
	SDL_GetMouseState(&mouse.x, &mouse.y);
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT:
			SDL_Quit();
		case SDL_WINDOWEVENT_FOCUS_LOST:
			mouse.x = 0;
			mouse.y = 0;
		}
	}
}
Game::~Game() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
