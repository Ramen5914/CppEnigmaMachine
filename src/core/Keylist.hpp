#pragma once

#include <array>
#include <map>
#include <nlohmann/json.hpp>
#include <string>

struct DailyKey {
    std::array<std::string, 3> rotors;
    std::array<int, 3> ringPosition;
    std::array<std::string, 10> plugboard;
    std::array<std::string, 5> keyGroups;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(DailyKey, rotors, ringPosition, plugboard, keyGroups)
};

class Keylist {
   private:
    std::map<std::string, DailyKey> dailyKeys;
    std::array<std::string, 300> decoyGroups;

   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Keylist, dailyKeys, decoyGroups);

    std::map<std::string, DailyKey>& getDailyKeys();
    const std::map<std::string, DailyKey> getDailyKeys() const;

    std::array<std::string, 300>& getDecoyGroups();
    const std::array<std::string, 300> getDecoyGroups() const;
};
