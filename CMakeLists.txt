cmake_minimum_required(VERSION 3.20.0)

project(cpp-playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

# Remove for compiler-specific features
set(CMAKE_CXX_EXTENSIONS OFF)

# clangd completion
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

string(APPEND CMAKE_CXX_FLAGS " -Wall")
string(APPEND CMAKE_CXX_FLAGS " -Wbuiltin-macro-redefined")
string(APPEND CMAKE_CXX_FLAGS " -pedantic")
string(APPEND CMAKE_CXX_FLAGS " -Werror")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-parameter")

add_subdirectory(dependencies)
add_subdirectory(apps)
