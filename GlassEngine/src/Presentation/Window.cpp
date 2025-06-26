#include "gpch.hpp"
#include "Presentation/Window.hpp"
#include "Context/OpenGLContext.hpp"
#include "Imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include <backends/imgui_impl_opengl3.h>
#include <UIManager/UIManager.hpp>

UWindow::UWindow() : sdlEvent{} {

}

UWindow::~UWindow() {
	if (openGLContext) {
		delete openGLContext; // Destroi o contexto OpenGL
	}
	//SDL_DestroyRenderer(sdlRenderer);
	if (sdlWindow) {
		SDL_DestroyWindow(sdlWindow);
	}
	if (SDL_WasInit(SDL_INIT_VIDEO)) {
		SDL_Quit();
	}

}

void UWindow::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
		SDL_Log("Erro ao inicializar SDL: %s", SDL_GetError());
		return;
	}

	// Criação da janela principal
	sdlWindow = SDL_CreateWindow("GlassEngine", 1200, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (!sdlWindow) {
		SDL_Log("Janela não foi criada: %s", SDL_GetError());
		return;
	}

	// Inicializa��o do ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& IO = ImGui::GetIO();
	(void)IO;
	IO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;// Habilita navegação por teclado
	ImGui::StyleColorsDark();
	openGLContext = new OpenGLContext(sdlWindow);
	try {
		openGLContext->Initialize();
	}
	catch (const std::exception& e) {
		SDL_Log("Erro durante inicialização do OpenGL: %s", e.what());
		return;
	}
	ImGui_ImplSDL3_InitForOpenGL(sdlWindow, openGLContext->GetGLContext());
	ImGui_ImplOpenGL3_Init("#version 450");
	// Inicialização do contexto OpenGL

}

bool UWindow::ShouldClose()
{
	return bShouldClose;
}

void UWindow::PollEvents
() {
	// Processa eventos do SDL
	while (SDL_PollEvent(&sdlEvent)) {
		ImGui_ImplSDL3_ProcessEvent(&sdlEvent);
		if (sdlEvent.type == SDL_EVENT_QUIT) {
			bShouldClose = true;
		}
	}
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL3_NewFrame();
	ImGui::NewFrame();

	static UIManager uiManager(sdlWindow);
	uiManager.RenderUI();
	// Janela de teste básica do ImGui
	ImGui::Begin("Janela Teste");
	ImGui::Text("Se você está vendo isso, o ImGui está funcionando!");
	ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	int width, height;
	SDL_GetWindowSize(sdlWindow, &width, &height);
	glViewport(0, 0, width, height);
	// Limpeza do framebuffer com OpenGL
	glClearColor(0.1f, 0.9f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Renderiza os dados do ImGui

	// Troca os buffers para exibir
	if (openGLContext) {
		openGLContext->SwapBuffers();
	}
	SDL_Delay(1);
}