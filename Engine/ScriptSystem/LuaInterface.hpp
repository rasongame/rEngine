//
// Created by User on 28.07.2020.
//

#ifndef SDL_GAME_LUAINTERFACE_HPP
#define SDL_GAME_LUAINTERFACE_HPP
#pragma once
#pragma comment(lib, "lua5.1.lib")
#include <Core/game.hpp>

class LuaInterface {

public:
    LuaInterface();

    LuaInterface(Game *const game);
};


#endif //SDL_GAME_LUAINTERFACE_HPP
