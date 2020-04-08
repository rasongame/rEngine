#include "game.hpp"
#include <SDL2/SDL_image.h>

#include <filesystem>
namespace fs = std::filesystem;
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
	logger.printInfo("Starting listing resources directory");
	int i = 0;
	for (const auto & entry : fs::directory_iterator("Resources/Textures")) {
		logger.printInfo(entry.path());
		textures[i] = IMG_LoadTexture(renderer, entry.path().c_str());
		i++;

	}
	surface = SDL_GetWindowSurface(window);

}
int c = 0;
void Game::render() {
	SDL_RenderClear(renderer);

//	logger.printInfo(std::to_string(mouse.x));
//	logger.printInfo(std::to_string(mouse.y));
	Rectangle rect(renderer, mouse.x-32, mouse.y-32, 64, 64);
	Rectangle rect_helmet(renderer, width/3, height/4, 64,64);
	SDL_RenderCopy(renderer, textures[0], NULL, &rect_helmet.rect);
	SDL_RenderPresent(renderer);
	//	SDL_UpdateWindowSurface(window);
}
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
			SDL_Quit();
		case SDL_MOUSEWHEEL:
			handleScroll(event);
		}
	}
}
Game::~Game() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
