#include "gpch.hpp"
#include "Components/FileSystem.hpp"
#include "imgui.h"

UFileSystem::UFileSystem()
    : currentPath("E:/Desenvolvimento/Engine/GlassEngine/Assets") // Define a pasta pai
{
}

UFileSystem::~UFileSystem()
{
}

void UFileSystem::SetCurrentPath(const std::filesystem::path& path)
{
    currentPath = path;
}

const std::filesystem::path& UFileSystem::GetCurrentPath() const
{
    return currentPath;
}

void UFileSystem::GoToParentDirectory()
{
    if (currentPath.has_parent_path()) {
        currentPath = currentPath.parent_path();
    }
}

void UFileSystem::CreateDirectory(const std::string& name)
{
    std::filesystem::create_directory(currentPath / name);
}

void UFileSystem::DeleteDirectory(const std::filesystem::path& path)
{
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
        std::filesystem::remove_all(path);
    }
}

void UFileSystem::RenameDirectory(const std::filesystem::path& oldPath, const std::string& newName)
{
    std::filesystem::rename(oldPath, oldPath.parent_path() / newName);
}

void UFileSystem::ShowDirectoryTree()
{
    // Barra de navegação com o caminho atual e botão para voltar
    ImGui::Text("Diretório Atual: %s", currentPath.string().c_str());
    if (ImGui::Button("Voltar")) {
        GoToParentDirectory();
    }

    ImGui::Separator();

    // Layout em grade para mostrar pastas e arquivos
    int columnCount = 5; // Define o número de colunas na grade
    ImGui::Columns(columnCount, NULL, false);

    // Exibir conteúdo da pasta atual
    for (const auto& entry : std::filesystem::directory_iterator(currentPath))
    {
        if (entry.is_directory())
        {
            bool openRenamePopup = false;

            // Botão que representa a pasta
            if (ImGui::Button(entry.path().filename().string().c_str(), ImVec2(100, 100))) {
                SetCurrentPath(entry.path());
            }

            // Menu de contexto para a pasta
            if (ImGui::BeginPopupContextItem(entry.path().filename().string().c_str())) {
                if (ImGui::Selectable("Excluir Pasta")) {
                    DeleteDirectory(entry.path());
                }
                if (ImGui::Selectable("Renomear Pasta")) {
                    openRenamePopup = true;  // Define a flag para abrir o popup de renomear
                }
                ImGui::EndPopup();
            }

            // Abre o popup de renomear se a opção foi selecionada
            if (openRenamePopup) {
                ImGui::OpenPopup("Renomear Pasta");
            }

            // Popup para renomear a pasta
            if (ImGui::BeginPopupModal("Renomear Pasta", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
                static char newName[128] = "";
                ImGui::InputText("Novo Nome", newName, sizeof(newName));

                if (ImGui::Button("Confirmar")) {
                    if (strlen(newName) > 0) {
                        RenameDirectory(entry.path(), newName);
                        newName[0] = '\0';  // Limpa o nome após renomear
                    }
                    ImGui::CloseCurrentPopup();
                }
                ImGui::SameLine();
                if (ImGui::Button("Cancelar")) {
                    ImGui::CloseCurrentPopup();
                }

                ImGui::EndPopup();
            }
        }
        else
        {
            // Ícone do arquivo
            ImGui::TextWrapped(entry.path().filename().string().c_str());
        }
        ImGui::NextColumn();
    }
    ImGui::Columns(1); // Retorna para uma única coluna

    // Menu de contexto para criar nova pasta ao clicar com o botão direito fora de qualquer item
    if (ImGui::BeginPopupContextWindow()) {
        static char newFolderName[128] = "";

        ImGui::InputText("Nome da Nova Pasta", newFolderName, sizeof(newFolderName));
        if (ImGui::Selectable("Criar Pasta")) {
            if (strlen(newFolderName) > 0) {
                CreateDirectory(newFolderName);
                newFolderName[0] = '\0';
            }
        }

        ImGui::EndPopup();
    }
}
