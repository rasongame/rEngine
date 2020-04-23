#ifndef RENDERUTILS_H
#define RENDERUTILS_H
#pragma once
#include <vector>
using namespace std;
namespace RenderUtils {
    std::vector<std::vector<int>> getVerticesForPosition(int x,int y, int width, int height) {
        std::vector<std::vector<int>> vertices =
        {
                {x,y, x+width, y+height},
                {x+width, y+height, x-width, y+height},
                {x-width, y+height, x,y},
        };
        return vertices;
}
}


#endif // RENDERUTILS_H
