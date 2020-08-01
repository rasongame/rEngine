cmake_minimum_required(VERSION 3.5)

project(SDL_game LANGUAGES CXX)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_REENTRANT")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(Engine)
set(LUA_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/thirdparty/luajit")
find_package(Lua     REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
add_definitions(-DLUA)
get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

add_executable(SDL_game WIN32 main.cpp
        Engine/Render/RenderUtils.hpp
        Engine/Core/game.cpp
        Engine/Logger/Logger.cpp
        Engine/Render/Rectangle.cpp
        Engine/Render/Triangle.cpp
        Engine/Core/utils.cpp
        Engine/Render/pseudo3dcube.cpp
        Engine/Render/pseudo3dtriangle.cpp
        Engine/Render/RenderUtils.cpp
        Engine/Core/settings.hpp Engine/ScriptSystem/test.cpp Engine/ScriptSystem/test.hpp Engine/ScriptSystem/LuaInterface.cpp Engine/ScriptSystem/LuaInterface.hpp Engine/Core/debug.hpp Engine/Core/debug.cpp Engine/ScriptSystem/LuaUtils.hpp Engine/Common/common.hpp Engine/ScriptSystem/LuaUtils.cpp Engine/Common/Enums.hpp)

target_link_libraries(SDL_game  SDL2::SDL2 SDL2::SDL2_image ${LUA_LIBRARY})
