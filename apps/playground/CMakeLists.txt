# CMakeLists.txt

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  # set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# SET(CHECK_DATARACE_FLAG "-fsanitize=thread")
SET(CHECK_DATARACE_FLAG "")

SET(CHECK_LEAK_FLAG "-fsanitize=address")

# SET(CHECK_LEAK_FLAG "")
# ./a.out > sanitize.log 2>&1
SET(COMPILE_WARNNING_FLAG "-Wall -Wextra -Wno-unused-parameter")

set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${COMPILE_WARNNING_FLAG} ${CHECK_DATARACE_FLAG} ${CHECK_LEAK_FLAG}")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

########################################
add_executable(hello
  ./src/hello.cpp
)
target_link_libraries(hello 
    spdlog::spdlog_header_only
)
########################################

########################################
add_executable(measure
  ./src/measure.cpp
)
target_link_libraries(measure 
    fmt::fmt 
    spdlog::spdlog_header_only
)
########################################

########################################
add_executable(fmt_test
  ./src/fmt_test.cpp
)
target_link_libraries(fmt_test 
    fmt::fmt
)
########################################

########################################
add_executable(concurrency
  ./src/concurrency.cpp
)
########################################
