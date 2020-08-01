//
// Created by User on 28.07.2020.
//
#pragma once
#ifndef SDL_GAME_COMMON_HPP
#define SDL_GAME_COMMON_HPP
extern "C" {

#include <luajit/lua.h>
#include <luajit/lauxlib.h>
#include <luajit/lualib.h>

};

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <Logger/Logger.hpp>
#include <Render/Triangle.hpp>
#include <Render/pseudo3dcube.hpp>
#include <Render/pseudo3dtriangle.hpp>
#include <Render/RenderUtils.hpp>
#include <Core/settings.hpp>
#include <filesystem>

#endif //SDL_GAME_COMMON_HPP
