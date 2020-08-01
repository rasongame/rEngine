//
// Created by User on 28.07.2020.
//

#ifndef SDL_GAME_LUAUTILS_HPP
#define SDL_GAME_LUAUTILS_HP
extern "C" {

#include <luajit/lua.h>
#include <luajit/lauxlib.h>
#include <luajit/lualib.h>

};
namespace LuaUtils {
    int getTitle(lua_State *l);
    int setTitle(lua_State *l);
}
#endif //SDL_GAME_LUAUTILS_HPP
