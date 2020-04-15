#include <iostream>
#include "Engine/Core/game.hpp"
using namespace std;
#ifdef __linux__
int main()
#else
int WinMain()
#endif
{
    Game game;
    game.title = "rEngine";
    while(1) {
        game.update();
        game.render();
        SDL_Delay(10);
    }
    return -1;
}
