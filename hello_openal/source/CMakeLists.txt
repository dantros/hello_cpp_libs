cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)

project(hello_openal C CXX)

# Getting the parent directory twice
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH EXAMPLE_DIR)
cmake_path(GET EXAMPLE_DIR PARENT_PATH REPO_DIR)

add_executable(hello_openal "hello_openal.cpp")
set_property(TARGET hello_openal PROPERTY CXX_STANDARD 20)

# Do note that OpenAL32.lib is an import library, you you need to
# place OpenAL32.dll next to the .exe file to find the definitions
# during runtime.
target_link_libraries(hello_openal PRIVATE
    "${REPO_DIR}/libs/dr_libs/build/Release/dr_wav.lib"
    "${REPO_DIR}/libs/openal-soft/build/Release/OpenAL32.lib"
)
target_include_directories(hello_openal PRIVATE
    "${REPO_DIR}/libs/openal-soft/source/openal-soft/include"
    "${REPO_DIR}/libs/dr_libs/source/dr_libs"
)