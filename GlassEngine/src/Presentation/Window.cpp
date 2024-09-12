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
        SDL_Log("SDL n�o inicializado");
        return;
    }

    // Cria��o da janela principal
    sdlWindow = SDL_CreateWindow("GlassEngine", 1200, 720, flags);
    if (!sdlWindow) {
        SDL_Log("Janela n�o foi criada!");
        return;
    }

    // Renderizador SDL
    sdlRenderer = SDL_CreateRenderer(sdlWindow, NULL);
    if (!sdlWindow) {
        SDL_Log("Rendere n�o foi criado!");
        return;
    }

    // Inicializa��o do ImGui
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
            if (sdlEvent.key.key == SDLK_ESCAPE)
                bShouldClose = true;
            break;
        default:
            break;
        }
    }

    // Inicia novos frames do ImGui e SDL
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();

    ImGui::NewFrame();

    // Exibe a janela "Hello World"
    {
        ImGui::Begin("Pasta");
        {
            if (ImGui::Button("Sair")) {
                bShouldClose = true;
            }
            ImGui::Separator();
            ImGui::Text("File System:");
            fileSystem.ShowDirectoryTree(); // Exibe o sistema de arquivos
        }
        ImGui::End();
    }

    // Exibe a nova janela "vulkanjanelar"
    {
        ImGui::Begin("VulkanJanelar"); // Cria a janela Vulkan
        {
            ImGui::Text("Aqui sera renderizado o conte�do do Vulkan.");
        }
        ImGui::End();
    } 

    {
        ImGui::Begin("Pastas"); // Cria a janela Vulkan
        {
            ImGui::Text("Aqui sera renderizado o conte�do do pasta.");
            ImGui::Separator();
            ImGui::Text("File System:");
            fileSystem.ShowDirectoryTree();
        }
        ImGui::End();
    }

    // Renderiza os elementos
    ImGui::Render();
    SDL_SetRenderDrawColor(sdlRenderer, 25, 25, 255, 0xff);
    SDL_RenderClear(sdlRenderer);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), sdlRenderer);
    SDL_RenderPresent(sdlRenderer);
    SDL_Delay(1);
}