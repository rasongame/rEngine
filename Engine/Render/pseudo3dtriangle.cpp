#include "pseudo3dtriangle.hpp"
pseudo3dtriangle::pseudo3dtriangle(SDL_Renderer *renderer,
                                   const std::vector<int> vert1,const std::vector<int> vert2,const std::vector<int> vert3,
                                   const std::vector<int> vert4,const std::vector<int> vert5,const std::vector<int> vert6)
{
    SDL_SetRenderDrawColor(renderer, 0xff,0xff, 0xff, 0xff);
    SDL_RenderDrawLine(renderer, vert1[0], vert1[1], vert1[2], vert1[3]);
    SDL_RenderDrawLine(renderer, vert2[0], vert2[1], vert2[2], vert2[3]);
    SDL_RenderDrawLine(renderer, vert3[0], vert3[1], vert3[2], vert3[3]);


    SDL_RenderDrawLine(renderer, vert4[0], vert4[1], vert4[2], vert4[3]);
    SDL_RenderDrawLine(renderer, vert5[0], vert5[1], vert5[2], vert5[3]);
    SDL_RenderDrawLine(renderer, vert6[0], vert6[1], vert6[2], vert6[3]);

    SDL_RenderDrawLine(renderer, vert1[0], vert1[1], vert4[0], vert4[1]);
    SDL_RenderDrawLine(renderer, vert2[0], vert2[1], vert5[0], vert5[1]);
    SDL_RenderDrawLine(renderer, vert3[0], vert3[1], vert6[0], vert6[1]);

    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0 );
}
