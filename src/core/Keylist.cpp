#include "Keylist.hpp"

std::map<std::string, DailyKey>& Keylist::getDailyKeys() {
    return dailyKeys;
}
const std::map<std::string, DailyKey> Keylist::getDailyKeys() const {
    return dailyKeys;
}

std::array<std::string, 300>& Keylist::getDecoyGroups() {
    return decoyGroups;
}
const std::array<std::string, 300> Keylist::getDecoyGroups() const {
    return decoyGroups;
}
