cmake_minimum_required(VERSION 3.28)
project(ota-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(ENABLE_COVERAGE "Enable coverage reporting" ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE STREQUAL "Coverage" AND ENABLE_COVERAGE)
    message(STATUS "Building with coverage flags")
    add_compile_options(--coverage -O0 -g)
    link_libraries(gcov)

    find_program(LCOV_PATH lcov)
    find_program(GENHTML_PATH genhtml)
    find_program(CTEST_PATH ctest)

    if(LCOV_PATH AND GENHTML_PATH AND CTEST_PATH)
        add_custom_target(coverage
        COMMAND ${CTEST_PATH} --output-on-failure
        COMMAND ${LCOV_PATH} --directory . --capture --ignore-errors mismatch --output-file coverage.info
        COMMAND ${LCOV_PATH} --remove coverage.info '/usr/*' '*/_deps/*' '*/tests/*' --output-file coverage.info
        COMMAND ${GENHTML_PATH} coverage.info --output-directory coverage-report
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running tests and generating code coverage report in coverage-report/"
)

    else()
        message(WARNING "lcov/genhtml/ctest not found! 'coverage' target will be unavailable.")
    endif()

elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug build: adding debug symbols")
    add_compile_options(-g -O0)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Release build: optimizing")
    add_compile_options(-O3 -DNDEBUG)
endif()

# Add sources
add_library(ota
    src/updater.cpp
    src/manifest.cpp
)

target_include_directories(ota PUBLIC include)
target_link_libraries(ota PUBLIC nlohmann_json::nlohmann_json)


# ---------------------------
# FetchContent for gtest
# ---------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)

# Copy test JSON files to the build directory for the test executable
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/qemu-test/manifests/valid.json
    ${CMAKE_CURRENT_BINARY_DIR}/tests/valid.json
    COPYONLY
)

FetchContent_MakeAvailable(googletest)

# ---------------------------
# FetchContent for nlohmann/json
# ---------------------------
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/archive/refs/tags/v3.11.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)

FetchContent_MakeAvailable(json)

# Unit tests
enable_testing()
add_subdirectory(tests)

# CLI tool
add_executable(otactl tools/otactl/main.cpp)
target_link_libraries(otactl ota)
