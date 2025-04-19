#include <fmt/core.h>
#include <CLI/CLI.hpp>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include "utils/FileUtils.hpp"

using json = nlohmann::json;
using namespace std;

json createOrLoadCodeBook(const string& path);

int main(int argc, char** argv) {
    CLI::App app{"A feature-rich software implementation of the Enigma Machine."};

    auto fileStore = FileUtils::getUserDataDirectory("enigma");

    string codebookPath = fileStore / "codebooks" / "default.json";
    app.add_option("-c,--codebook", codebookPath, "The path of your codebook");

    CLI11_PARSE(app, argc, argv);

    json codebook = createOrLoadCodeBook(codebookPath);

    fmt::print("Loaded codebook from {}:\n{}\n", codebookPath, codebook.dump(4));

    return 0;
}

json createOrLoadCodeBook(const string& path) {
    json j;

    namespace fs = filesystem;

    // If the file exists, try to open and parse it
    if (fs::exists(path)) {
        ifstream in(path);
        in.close();

        if (!in.is_open()) {
            cerr << "Failed to open existing codebook: " << path << endl;
            return nullptr;
        }

        try {
            in >> j;
            return j;
        } catch (const json::parse_error& e) {
            cerr << "Failed to parse codebook: " << e.what() << endl;
            return nullptr;
        }
    }

    // If file does not exist, create default structure
    j = {{"reflector", json::array()}, {"plugboard", json::array()}, {"rotors", json::array()}};

    // Ensure directory exists before writing
    fs::create_directories(fs::path(path).parent_path());

    ofstream out(path);
    if (!out.is_open()) {
        cerr << "Error creating new codebook at: " << path << endl;
        return nullptr;
    }

    out << j.dump(4);
    return j;
}