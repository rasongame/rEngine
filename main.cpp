#include <iostream>
#include "Engine/Core/game.hpp"
#ifdef __linux__
void ifRectOutOfScreen(Rectangle *rect, Game *game) {
	if (rect->x+rect->w < 0){
		rect->x = game->width-25;
	} else if(rect->x+rect->w > game->width) {
		rect->x = 0-25;
	}
	if (rect->y+rect->h > game->height) {
		rect->y = 0+rect->h/2;
	} else if(rect->y+rect->h < 0-50) {
		rect->y = game->height-5;
	}
}
int main()
#else
int WinMain()
#endif

{
	Game *game = new Game;
	game->changeTitle("rEngine");
	game->mouse_rect = new Rectangle(game->renderer, game->mouse.x-25, game->mouse.y-25, 50, 50);
	game->player = new Rectangle(game->renderer, game->height-175, 100, 25, 25);
    while(1) {
		SDL_RenderClear(game->renderer);
		game->update();
		game->mouse_rect->Render(game->mouse.x-25, game->mouse.y-25);
		game->player->Render(game->player->x, game->player->y);
//		Logger().printInfo(std::to_string(game->player.x));
//		Logger().printInfo(std::to_string(game->player.y));
		ifRectOutOfScreen(game->player, game);
		game->render();
        SDL_Delay(10);
    }
    return -1;
}
