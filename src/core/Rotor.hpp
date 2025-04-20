#include <array>
#include <string>
#include <vector>
#include "../utils/SizedVector.hpp"

class Rotor {
   private:
    std::string name;
    std::array<int, 26> wiring;
    std::array<int, 26> reverseWiring;
    SizedVector<int, 1, 26> notchPositions;
};
