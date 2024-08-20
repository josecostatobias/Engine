#include "gpch.hpp"
#include "Components/FileSystem.hpp"
#include "imgui.h"

UFileSystem::UFileSystem()
    : currentPath(std::filesystem::current_path()) // Inicia no diretório atual
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

void UFileSystem::ShowDirectoryTree()
{
    for (const auto& entry : std::filesystem::directory_iterator(currentPath))
    {
        if (entry.is_directory())
        {
            if (ImGui::TreeNode(entry.path().filename().string().c_str()))
            {
                SetCurrentPath(entry.path());
                ShowDirectoryTree();
                ImGui::TreePop();
            }
        }
        else
        {
            ImGui::Text(entry.path().filename().string().c_str());
        }
    }
}