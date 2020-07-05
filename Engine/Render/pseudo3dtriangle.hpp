#ifndef PSEUDO3DTRIANGLE_HPP
#define PSEUDO3DTRIANGLE_HPP
#include <vector>
#include <SDL2/SDL.h>

class pseudo3dtriangle
{
public:
    pseudo3dtriangle(SDL_Renderer *renderer,
                     const std::vector<int> vert1,const std::vector<int> vert2,const std::vector<int> vert3,
                     const std::vector<int> vert4,const std::vector<int> vert5,const std::vector<int> vert6);
};

#endif // PSEUDO3DTRIANGLE_HPP
