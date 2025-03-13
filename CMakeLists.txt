cmake_minimum_required(VERSION 3.16)
project(GitHubRepoCLI)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable FetchContent for dependency management
include(FetchContent)

# Ensure OpenSSL and CURL are used from the system
set(CPR_USE_SYSTEM_CURL ON CACHE BOOL "" FORCE)
set(CMAKE_USE_OPENSSL ON CACHE BOOL "" FORCE)

# Fetch CPR (HTTP client)
FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 1.10.5
)
FetchContent_MakeAvailable(cpr)

# Fetch nlohmann/json (JSON parsing)
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

# Enable FetchContent for dependency management
include(FetchContent)

# Fetch FTXUI
FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

# Add the executable
add_executable(gitrep src/main.cpp)

# Link required libraries
target_link_libraries(gitrep PRIVATE cpr::cpr ftxui::screen ftxui::dom ftxui::component nlohmann_json::nlohmann_json)

add_custom_target(copy_config ALL
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/src/config.ini ${CMAKE_BINARY_DIR}
    COMMENT "Copying config.ini to build directory"
)