#include "gpch.hpp"
#include "UIManager/UIManager.hpp"
#include <filesystem>
#include <Renderer/OpenGLRenderer.hpp>

UIManager::UIManager(SDL_Window* window)
	: sdlWindow(window) {
}

void UIManager::RenderUI() {
	if (ImGui::BeginMainMenuBar()) {
		if (ImGui::BeginMenu("Arquivo")) {
			if (ImGui::MenuItem("Novo Sistema de arquivos")) {
				// Ação para criar um novo projeto
			}
			ImGui::Separator(); // Linha separadora
			if (ImGui::MenuItem("Sair", "Alt+F4")) {
				// Ação para sair
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Ajuda")) {
			if (ImGui::MenuItem("Sobre")) {
				// Ação para exibir informações
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	ImGui::Begin("OpenGL Renderer");
	{
		static OpenGLRenderer* openGLRenderer = nullptr;
		if (!openGLRenderer) {
			openGLRenderer = new OpenGLRenderer(sdlWindow);
		}
		if (ImGui::Button("Renderizar Triângulo")) {
			openGLRenderer->Render();
		}
		ImGui::Text("Clique para renderizar um triângulo usando OpenGl.");
	}
	ImGui::End();

	ImGui::Begin("Sistema de arquivos");
	{
		fileSystem.ShowDirectoryTree();
	}
	ImGui::End();
}