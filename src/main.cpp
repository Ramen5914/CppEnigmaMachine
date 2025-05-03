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

    // Rotor
    CLI::App* rotor = app.add_subcommand("rotor");

    std::string rotorName;

    CLI::App* rotorAdd = rotor->add_subcommand("add");
    rotorAdd->add_option("name", rotorName, "Rotor name")->required();
    int notches = 1;
    rotorAdd->add_option("-n,--notches", notches, "Amount of notches on the rotor");
    int seed;
    rotorAdd->add_option("-s,--seed", seed, "Seed to use for generating rotor");

    CLI::App* rotorRm = rotor->add_subcommand("rm");
    rotorRm->add_option("name", rotorName, "Rotor name")->required();

    CLI::App* rotorList = rotor->add_subcommand("list");

    // Keylist
    CLI::App* keylistSubCmd = app.add_subcommand("keylist");

    CLI::App* keylistAddSubCmd = keylistSubCmd->add_subcommand("add");
    CLI::App* keylistRmSubCmd = keylistSubCmd->add_subcommand("rm");
    CLI::App* keylistListSubCmd = keylistSubCmd->add_subcommand("list");

    // Reflector
    CLI::App* reflectorSubCmd = app.add_subcommand("reflector");

    CLI::App* reflectorAddSubCmd = reflectorSubCmd->add_subcommand("add");
    CLI::App* reflectorRmSubCmd = reflectorSubCmd->add_subcommand("rm");
    CLI::App* reflectorListSubCmd = reflectorSubCmd->add_subcommand("list");

    CLI11_PARSE(app, argc, argv);

    fs::path userDataDir = FileUtils::getUserDataDirectory("enigma");

    return 0;
}
