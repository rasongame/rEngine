cmake_minimum_required(VERSION 3.5)

project(SDL_game LANGUAGES CXX)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_REENTRANT")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${project_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(Engine)
set(LUA_INCLUDE_DIR "D:/OldData/cprojects/rEngine/third_party/luajit-2.0")
FIND_PACKAGE(Lua 5.1 REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL_image REQUIRED)
add_definitions(-DLUA)

get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

add_executable(SDL_game main.cpp
        Engine/Render/RenderUtils.hpp
        Engine/Core/game.cpp
        Engine/Logger/Logger.cpp
        Engine/Render/Rectangle.cpp
        Engine/Render/Triangle.cpp
        Engine/Core/utils.cpp
        Engine/Render/pseudo3dcube.cpp
        Engine/Render/pseudo3dtriangle.cpp
        Engine/Render/RenderUtils.cpp
        Engine/Core/settings.hpp Engine/ScriptSystem/test.cpp Engine/ScriptSystem/test.hpp Engine/ScriptSystem/LuaInterface.cpp Engine/ScriptSystem/LuaInterface.hpp Engine/Core/debug.hpp Engine/Core/debug.cpp Engine/ScriptSystem/LuaUtils.hpp Engine/Common/common.hpp Engine/ScriptSystem/LuaUtils.cpp)

target_link_libraries(SDL_game SDL2 SDL2_image luajit-5.1 ${LUA_LIBRARY})
