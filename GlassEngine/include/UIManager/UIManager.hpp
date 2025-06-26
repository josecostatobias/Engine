#pragma once

#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

#include "imgui.h"
#include "Components/FileSystem.hpp"
#include <SDL3/SDL.h>

class UIManager {
public:
    UIManager(SDL_Window* window);
    //UIManager() = default;
    ~UIManager() = default;

    void RenderUI();
private:
    UFileSystem fileSystem;
    SDL_Window* sdlWindow;
};

#endif 