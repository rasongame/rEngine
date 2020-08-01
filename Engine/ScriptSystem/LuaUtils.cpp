//
// Created by User on 28.07.2020.
//
#include "LuaUtils.hpp"
#include "LuaInterface.hpp"
#pragma comment(lib, "lua5.1.lib")
using namespace LuaUtils;

int LuaUtils::getTitle(lua_State *l) {
    lua_pushstring(l, Game::getInstance()->title.c_str());
    return 1;
}
