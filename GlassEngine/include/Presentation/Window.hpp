#pragma once

#ifndef GE_WINDOW_HPP
#define	GE_WINDOW_HPP
#include "Core/Macro.hpp"
#include "SDL3/SDL.h"
#include "Core/CommonTypes.hpp"

class UWindow
{
public:

	DEFAULT_CONSTTRUCTORS(UWindow)
	void initialize();
protected:
private:
	SDL_Event sdlEvent;
	SDL_Window* sdlWindow = nullptr;
	SDL_Surface* sdlSurface = nullptr;
	SDL_Renderer* sdlRenderer = nullptr;
	SDL_GLContext sdlGLContext;
};



#endif // !GE_WINDOW_HPP