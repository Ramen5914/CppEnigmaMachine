#pragma once

#include <filesystem>
#include <string>

namespace FileUtils {
std::filesystem::path getUserDataDirectory(const std::string& appName);
}