cmake_minimum_required(VERSION 3.14)
project(Enigma)

set(CMAKE_CXX_STANDARD 23)

# Automatically use vcpkg for package management
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

file(GLOB_RECURSE UTILS_SRC src/utils/*.cpp)
file(GLOB_RECURSE CORE_SRC src/core/*.cpp)

file(GLOB_RECURSE ALL_SOURCE_FILES CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/src/**/*.cpp
     ${CMAKE_SOURCE_DIR}/src/**/*.hpp
)

add_custom_target(format
    COMMAND clang-format
    -i
    ${ALL_SOURCE_FILES}
    COMMENT "Formatting source files..."
)

# Define the executable
add_executable(enigma ${UTILS_SRC} ${CORE_SRC} src/main.cpp)

# Find and link fmt and CLI11
find_package(fmt CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(cryptopp CONFIG REQUIRED)

# Link the libraries
target_link_libraries(enigma PRIVATE fmt::fmt CLI11::CLI11 nlohmann_json::nlohmann_json cryptopp::cryptopp)
