#pragma once

#ifndef FILE_SYSTEM_HPP
#define FILE_SYSTEM_HPP

#include <string>
#include <filesystem>

class UFileSystem
{
public:
    UFileSystem();
    ~UFileSystem();

    void SetCurrentPath(const std::filesystem::path& path);
    const std::filesystem::path& GetCurrentPath() const;

    void ShowDirectoryTree();
    void CreateDirectory(const std::string& name);
    void DeleteDirectory(const std::filesystem::path& path);
    void RenameDirectory(const std::filesystem::path& oldPath, const std::string& newName);
    void GoToParentDirectory();

private:
    std::filesystem::path currentPath;
};

#endif 