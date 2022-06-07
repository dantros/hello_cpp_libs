cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)

project(hello_boost C CXX)

# Getting the parent directory twice
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH EXAMPLE_DIR)
cmake_path(GET EXAMPLE_DIR PARENT_PATH REPO_DIR)

# A first example with a header only library
add_executable(hello_boost_header_only "hello_boost_header_only.cpp")
set_property(TARGET hello_boost_header_only PROPERTY CXX_STANDARD 20)
target_include_directories(hello_boost_header_only PRIVATE
    "${REPO_DIR}/libs/boost/install/include/boost-1_79"
)

# A second example that requires to build boost. Check the .cpp for simplified directions.
add_executable(hello_boost_binary "hello_boost_binary.cpp")
set_property(TARGET hello_boost_binary PROPERTY CXX_STANDARD 20)
target_link_libraries(hello_boost_binary PRIVATE
    "${REPO_DIR}/libs/boost/install/lib/libboost_serialization-vc143-mt-x64-1_79.lib"
)
target_include_directories(hello_boost_binary PRIVATE
    "${REPO_DIR}/libs/boost/install/include/boost-1_79"
)