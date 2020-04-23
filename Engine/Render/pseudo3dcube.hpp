#ifndef PSEUDO3DCUBE_H
#define PSEUDO3DCUBE_H
#include <SDL2/SDL.h>
#include "Rectangle.hpp"
class Pseudo3dCube
{
public:
    Pseudo3dCube(SDL_Renderer *renderer, int x, int y, int w, int h, int diff);
    Rectangle rectOne;
    Rectangle rectTwo;

};

#endif // PSEUDO3DCUBE_H
