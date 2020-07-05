#include "Triangle.hpp"

Triangle::Triangle(SDL_Renderer *renderer, const std::vector<int> vert1,const std::vector<int> vert2,const std::vector<int> vert3) {
//    this->x = x;
//    this->y = y;
//    this->z = z;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, vert1[0], vert1[1], vert1[2], vert1[3]);
    SDL_RenderDrawLine(renderer, vert2[0], vert2[1], vert2[2], vert2[3]);
    SDL_RenderDrawLine(renderer, vert3[0], vert3[1], vert3[2], vert3[3]);
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0 );
}
