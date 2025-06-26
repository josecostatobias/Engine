#include "gpch.hpp"
#include "Renderer/OpenGLRenderer.hpp"
#include <glad/glad.h>
#include <SDL3/SDL.h>
#include <iostream>

OpenGLRenderer::OpenGLRenderer(SDL_Window* window)
	: sdlWindow(window) {
	if (!sdlWindow) {
		std::cerr << "Erro: SDL_Window não foi inicializado corretamente!" << std::endl;
		return;
	}
	InitializeOpenGL();
}

OpenGLRenderer::~OpenGLRenderer() {
	if (glContext) {
		SDL_GL_DestroyContext(glContext);
	}
}
void OpenGLRenderer::InitializeOpenGL() {
	// Criação do contexto OpenGL
	glContext = SDL_GL_CreateContext(sdlWindow);
	if (!glContext) {
		std::cerr << "Erro ao criar contexto OpenGL: " << SDL_GetError() << std::endl;
		return;
	}
	std::cout << "Contexto OpenGL criado com sucesso!" << std::endl;
	// Inicialização do Glad
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		std::cerr << "Erro ao inicializar Glad!" << std::endl;
		return;
	}
	std::cout << "GLAD inicializado com sucesso!" << std::endl;
	// Configurações básicas do OpenGL
	glViewport(0, 0, 1200, 720); // Tamanho da viewport
	glEnable(GL_DEPTH_TEST);
	std::cout << "OpenGL configurado com sucesso! Versão: " << glGetString(GL_VERSION) << std::endl;
}

void OpenGLRenderer::Render() {
	if (!sdlWindow || !glContext) {
		std::cerr << "Erro: SDL_Window ou OpenGL Context não estão válidos na chamada de Render!" << std::endl;
		return;
	}

	// Cor de fundo
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Aqui você pode adicionar o código para desenhar um triângulo simples usando shaders

	SDL_GL_SwapWindow(sdlWindow); // Troca os buffers para exibir a renderização
}