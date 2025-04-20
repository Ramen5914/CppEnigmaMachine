#include "FileUtils.hpp"

#include <cstdlib>
#include <stdexcept>

namespace FileUtils {
std::filesystem::path getUserDataDirectory(const std::string& appName) {
    namespace fs = std::filesystem;

#if defined(_WIN32)
    const char* appData = std::getenv("LOCALAPPDATA");
    if (!appData) throw std::runtime_error("LOCALAPPDATA not found");

    return fs::path(appData) / appName;
#elif defined(__APPLE__)
    const char* home = std::getenv("HOME");
    if (!home) throw std::runtime_error("HOME not found");

    return fs::path(home) / "Library" / "Application Support" / appName;
#else
    const char* xdgData = std::getenv("XDG_DATA_HOME");
    const char* home = std::getenv("HOME");

    if (xdgData) return fs::path(xdgData) / appName;
    if (home) return fs::path(home) / ".local" / "share" / appName;

    throw std::runtime_error("No useable home directory");
#endif
}
}  // namespace FileUtils
