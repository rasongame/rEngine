//
// Created by User on 28.07.2020.
//

#ifndef SDL_GAME_LUAUTILS_HPP
#define SDL_GAME_LUAUTILS_HP
extern "C" {

#include <luajit-2.0/lua.h>
#include <luajit-2.0/lauxlib.h>
#include <luajit-2.0/lualib.h>

};
namespace LuaUtils {
    int getTitle(lua_State *l);
}
#endif //SDL_GAME_LUAUTILS_HPP
