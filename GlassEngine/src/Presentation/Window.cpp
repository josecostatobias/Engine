#include "gpch.hpp"
#include "Presentation/Window.hpp"

#include "Imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

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
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& IO = ImGui::GetIO();
	(void)IO;
	IO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	ImGui::StyleColorsDark();
	ImGui_ImplSDL3_InitForSDLRenderer(sdlWindow, sdlRenderer);
	ImGui_ImplSDLRenderer3_Init(sdlRenderer);
}

bool UWindow::ShouldClose()
{

	return bShouldClose;
}

void UWindow::PollEvents()
{
	while (SDL_PollEvent(&sdlEvent)) {

		ImGui_ImplSDL3_ProcessEvent(&sdlEvent);
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
	
	ImGui_ImplSDLRenderer3_NewFrame();
	ImGui_ImplSDL3_NewFrame();

	ImGui::NewFrame();
	{
		ImGui::Begin("Hello World");
		{
			if (ImGui::Button("Sair")) {
				bShouldClose = true;
			}
			
		}
		ImGui::End();
	}
	ImGui::Render();

	SDL_SetRenderDrawColor(sdlRenderer,25,25,255,0xff);
	SDL_RenderClear(sdlRenderer);
	ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(),sdlRenderer);
	SDL_RenderPresent(sdlRenderer);
	SDL_Delay(1);
		
}
