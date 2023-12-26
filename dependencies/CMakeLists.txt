# FetchContent added in CMake 3.11, downloads during the configure step
# FetchContent_MakeAvailable was added in CMake 3.14; simpler usage
include(FetchContent)

# Accumulator library
# This is header only, so could be replaced with git submodules or FetchContent
# find_package(Boost REQUIRED)
# Adds Boost::boost

# ###############################################################################
#
# Formatting library
#
# ###############################################################################
FetchContent_Declare(
    fmtlib
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.0.0)

message(STATUS "Fetching fmtlib...")

FetchContent_MakeAvailable(fmtlib)

# ###############################################################################

# ###############################################################################
#
# spdlog library
#
# ###############################################################################
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.12.0)

message(STATUS "Fetching spdlog...")

FetchContent_MakeAvailable(spdlog)

# ###############################################################################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

# ###############################################################################
