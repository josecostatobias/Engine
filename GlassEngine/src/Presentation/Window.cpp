#include "gpch.hpp"
#include "Presentation/Window.hpp"
UWindow::UWindow() {

}
UWindow::~UWindow() {
	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyWindow(sdlWindow);

}

void UWindow::Initialize()
{
	int flags = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	if (flags < 0) {
		SDL_Log("SDL não inicializado");
		return;
	}

	sdlWindow = SDL_CreateWindow("GlassEngine", 1200, 720, flags);
	if (!sdlWindow) {
		SDL_Log("Janela não foi criada!");
		return;
	}

	sdlRenderer = SDL_CreateRenderer(sdlWindow, NULL);
	if (!sdlWindow) {
		SDL_Log("Rendere não foi criado!");
		return;
	}
}

bool UWindow::ShouldClose()
{

	return bShouldClose;
}

void UWindow::PollEvents()
{
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type)
		{
		case SDL_EVENT_QUIT:
			bShouldClose = true;
			break;
		case SDL_EVENT_KEY_DOWN:
			if(sdlEvent.key.key == SDLK_ESCAPE)
			bShouldClose = true;
			break;
		default:
			break;
		}
	}
	
	SDL_SetRenderDrawColor(sdlRenderer,0,0,0,0xff);
	SDL_RenderClear(sdlRenderer);
	SDL_RenderPresent(sdlRenderer);
	SDL_Delay(1);
		
}
