//
// Created by User on 28.07.2020.
//
#include "LuaUtils.hpp"
#include "LuaInterface.hpp"

using namespace LuaUtils;

int LuaUtils::getTitle(lua_State *l) {
    lua_pushstring(l, Game::getInstance()->title.c_str());
    return 1;
}
