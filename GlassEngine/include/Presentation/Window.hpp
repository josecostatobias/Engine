#pragma once

#ifndef GE_WINDOW_HPP
#define	GE_WINDOW_HPP
#include "SDL3/SDL.h"
#include "Core/Macro.hpp"
#include "Core/CommonTypes.hpp"
#include "Components/FileSystem.hpp"
#include "Renderer/OpenGLRenderer.hpp"
#include "Context/OpenGLContext.hpp"

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
	//SDL_Renderer* sdlRenderer = nullptr;
	OpenGLContext* openGLContext = nullptr;
	bool bShouldClose = false;
	UFileSystem fileSystem;
};



#endif // !GE_WINDOW_HPP