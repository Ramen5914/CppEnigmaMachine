#include <fmt/core.h>
#include <CLI/CLI.hpp>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include "utils/FileUtils.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;
using namespace std;

int main(int argc, char** argv) {
    CLI::App app{"A feature-rich software implementation of the Enigma Machine."};
    fs::path userDataDir = FileUtils::getUserDataDirectory("enigma");

    CLI11_PARSE(app, argc, argv);

    return 0;
}
