#include "gpch.hpp"
#include "Presentation/Window.hpp"
UWindow::UWindow() {

}
UWindow::~UWindow() {
	delete sdlWindow;
}

void UWindow::initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{

		uint32 windowFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED;

		SDL_PixelFormatDetails pfd{
		};
			sdlWindow = SDL_CreateWindow("GEngine"
				, 1270
				, 800
				, windowFlags);
			sdlRenderer = SDL_CreateRenderer(sdlWindow, 0);
			SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 0);
			SDL_RenderClear(sdlRenderer);
			SDL_RenderPresent(sdlRenderer);
			sdlSurface = SDL_GetWindowSurface(sdlWindow);
			SDL_FillSurfaceRect(sdlSurface, NULL, 0);
			SDL_UpdateWindowSurface(sdlWindow);
			sdlGLContext = SDL_GL_CreateContext(sdlWindow);
		

	}
}
