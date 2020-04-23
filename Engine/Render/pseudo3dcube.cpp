#include "pseudo3dcube.hpp"

Pseudo3dCube::Pseudo3dCube(SDL_Renderer *renderer, int x, int y, int w, int h, int diff)
{
    Rectangle rectOne(renderer, x,y,w,h);
    Rectangle rectTwo(renderer, x+diff,y+diff,w,h);
    this->rectOne = rectOne;
    this->rectOne = rectTwo;
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, rectOne.x, rectOne.y, rectTwo.x, rectTwo.y);
    SDL_RenderDrawLine(renderer, rectOne.x+rectOne.w, rectOne.y, rectTwo.x+rectTwo.w, rectTwo.y);
    SDL_RenderDrawLine(renderer, rectOne.x, rectOne.y+rectOne.h, rectTwo.x, rectTwo.y+rectTwo.h);
    SDL_RenderDrawLine(renderer, rectOne.x+rectOne.w, rectOne.y+rectOne.h, rectTwo.x+rectTwo.w,rectTwo.y+rectTwo.h);
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0 );
}
