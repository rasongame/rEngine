//
// Created by User on 28.07.2020.
//


#include <filesystem>
#include "LuaInterface.hpp"
#include "LuaUtils.hpp"
#include <Logger/Logger.hpp>

void loadAllScripts(std::string path, lua_State *l) {
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        Logger::printInfo("Loading script with name " + entry.path().string());
        luaL_dofile(l, entry.path().string().c_str());

    }
}

LuaInterface::LuaInterface() {

    auto l = luaL_newstate();
    luaL_openlibs(l);
    // Загрузка autoexec c файла...
    lua_register(l, "getTitle", LuaUtils::getTitle);
    std::string path = std::filesystem::current_path().string() + "/Resources/Scripts";
    Logger::printInfo(path);
    loadAllScripts(path, l);
    lua_close(l);
}

LuaInterface::LuaInterface(Game *const game) {
    LuaInterface();
}
//
//LuaInterface::LuaInterface(Game *pGame) {
//
//}
