#pragma once

#ifndef GE_WINDOW_HPP
#define	GE_WINDOW_HPP
#include "SDL3/SDL.h"
#include "Core/Macro.hpp"
#include "Core/CommonTypes.hpp"


class UWindow
{
public:

	DEFAULT_CONSTTRUCTORS(UWindow)
	void Initialize();
	bool ShouldClose();
	void PollEvents();
protected:
private:
	SDL_Event sdlEvent;
	SDL_Window* sdlWindow = nullptr;
	SDL_Renderer* sdlRenderer = nullptr;
	bool bShouldClose = false;
;
};



#endif // !GE_WINDOW_HPP