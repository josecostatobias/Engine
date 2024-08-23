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

private:
    std::filesystem::path currentPath;
};

#endif // FILE_SYSTEM_HPP