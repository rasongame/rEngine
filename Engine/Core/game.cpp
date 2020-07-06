//#include "game.cpp"
#include "game.hpp"
#include <SDL2/SDL_image.h>
#include <random>
#include <filesystem>

namespace fs = std::filesystem;
Game::Game()
{

	SDL_ShowCursor(SDL_DISABLE);
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	}

    Logger::printInfo("Creating renderer and window");
    window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
        Logger::printError("Window is NULL pointer");
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == nullptr) {
        Logger::printError("Renderer is NULL pointer");
    }
    Logger::printInfo("Starting listing resources directory");
	int i = 0;
	std::string path;
    path = "Resources/Textures";
    for (const auto & entry : fs::directory_iterator(path)) {
        Logger::printInfo(entry.path().string());
        textures[i] = IMG_LoadTexture(renderer, entry.path().string().c_str());

        i++;

    }
	surface = SDL_GetWindowSurface(window);

}
int c = 0;
/*
SDL использует систему координат считая от 0, 0 до размеров окна(640, 480)
Так что надо указывать первую позицию, например 128, 128
и вторую позицию, также по координатам окна вроде 640, 480
X1, Y1, X2, X2
*/
std::random_device rd;
std::mt19937 mersenne(rd()); // инициализируем Вихрь Мерсенна случайным стартовым числом
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,45);
void moveTrianSlowly(SDL_Renderer *renderer) {
    int dice_roll = distribution(generator);
    std::vector<std::vector<int>> verticesx = RenderUtils::getVerticesForPosition(368+dice_roll,368+dice_roll, 32, 32);
    std::vector<std::vector<int>> verticesy = RenderUtils::getVerticesForPosition(368-50+dice_roll,468+dice_roll, 32, 32);
    pseudo3dtriangle trian(renderer, verticesx[0], verticesx[1], verticesx[2],
                                     verticesy[0], verticesy[1],  verticesy[2]);
}
//	Rectangle rect_helmet(renderer, width-128, height/4, 128,64);
	//
	//  ебучая треугольная хуйня

//	std::vector<std::vector<int>> vertices = getVerticesForPosition(128, 128, 32, 32);
//	std::vector<std::vector<int>> vertices1 = getVerticesForPosition(256, 128, 32, 32);
//	std::vector<std::vector<int>> vertices2 = getVerticesForPosition(256-64, 256, 32, 32);
//	Triangle (renderer, vertices[0],vertices[1], vertices[2]);
//	Triangle (renderer, vertices1[0],vertices1[1], vertices1[2]);
//	Triangle (renderer, vertices2[0],vertices2[1], vertices2[2]);



//	for (int i = 0; i < 10; ++i) {
//		Pseudo3dCube cube(renderer, 25+(i<<6), 64, 30, 30, 15);
//	}
void Game::render() {
	mouse_rect->x = mouse.x-25;
	mouse_rect->y = mouse.y-25;
//    SDL_RenderCopy(renderer, textures[0], NULL, &rect_helmet.rect);
	SDL_RenderPresent(renderer);
	//	SDL_UpdateWindowSurface(window);
}
