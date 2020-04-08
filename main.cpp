#include <iostream>
#include "Engine/Core/game.hpp"

using namespace std;

int main()
{
	Game game;
	for (;;) {
		game.update();
		game.render();
		SDL_Delay(10);
	}
	cout << "Hello World!" << endl;
	return 0;
}
