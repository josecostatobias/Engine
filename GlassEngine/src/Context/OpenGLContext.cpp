#include "gpch.hpp"
#include "Context/OpenGLContext.hpp"
#include <iostream>
#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_sdl3.h>

OpenGLContext::OpenGLContext(SDL_Window* window)
    : sdlWindow(window), glContext(nullptr) {}

OpenGLContext::~OpenGLContext() {
    if (glContext) {
        SDL_GL_DestroyContext(glContext);
    }
}

void OpenGLContext::Initialize() {
    // Configurações do OpenGL antes de criar o contexto
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Criação do contexto OpenGL
    glContext = SDL_GL_CreateContext(sdlWindow);
    if (!glContext) {
        throw std::runtime_error("Erro ao criar contexto OpenGL: " + std::string(SDL_GetError()));
    }

    // Inicialização do Glad
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        throw std::runtime_error("Erro ao inicializar Glad!");
    }
    // Configuração do OpenGL
    SDL_GL_SetSwapInterval(1); // Habilitar VSync
    glViewport(0, 0, 1200, 720);
    glEnable(GL_DEPTH_TEST);

    // Exibir a versão do OpenGL no console
    std::cout << "OpenGL configurado com sucesso! Versão: " << glGetString(GL_VERSION) << std::endl;
}

SDL_GLContext OpenGLContext::GetGLContext() const {
    return glContext;
}

void OpenGLContext::SwapBuffers() {
    SDL_GL_SwapWindow(sdlWindow);
}
