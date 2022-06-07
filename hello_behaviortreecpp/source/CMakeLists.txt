cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)

project(hello_behaviortreecpp C CXX)

# Getting the parent directory twice
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH EXAMPLE_DIR)
cmake_path(GET EXAMPLE_DIR PARENT_PATH REPO_DIR)

add_executable(hello_behaviortreecpp
    "hello_behaviortreecpp.cpp"
    "dummy_nodes.h"
    "dummy_nodes.cpp"
)
set_property(TARGET hello_behaviortreecpp PROPERTY CXX_STANDARD 20)
target_link_libraries(hello_behaviortreecpp PRIVATE
    "${REPO_DIR}/libs/BehaviorTree.CPP/build/Release/behaviortree_cpp_v3.lib"
)
target_include_directories(hello_behaviortreecpp PRIVATE
"${REPO_DIR}/libs/BehaviorTree.CPP/source/BehaviorTree.CPP/include"
)