//
// Created by rason on 02.05.2020.
//
#include "RenderUtils.hpp"
std::vector<std::vector<int>> RenderUtils::getVerticesForPosition(int x,int y, int width, int height) {
    std::vector<std::vector<int>> vertices =
        {
                {x,         y,          x + width, y + height},
                {x + width, y + height, x - width, y + height},
                {x - width, y + height, x, y},
            };
    return vertices;
}