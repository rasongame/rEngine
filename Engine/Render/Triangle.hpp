//#include "../Logger/Logger.hpp"
#include <SDL2/SDL.h>
#include <vector>
class Triangle {
    public:
        Triangle(SDL_Renderer *renderer, const std::vector<int> vert1,const std::vector<int> vert2,const std::vector<int> vert3);
        int x, y, z;

};
