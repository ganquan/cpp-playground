# CMakeLists.txt

cmake_minimum_required(VERSION "3.17")

project(cpp-playground)

if(NOT CMAKE_BUILD_TYPE)
  # set(CMAKE_BUILD_TYPE Release)
  set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# SET(CHECK_DATARACE_FLAG "-fsanitize=thread")
SET(CHECK_DATARACE_FLAG "")

SET(CHECK_LEAK_FLAG "-fsanitize=address")
# SET(CHECK_LEAK_FLAG "")
# ./a.out > sanitize.log 2>&1 

SET(COMPILE_WARNNING_FLAG "-Wall -Wextra")

set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${COMPILE_WARNNING_FLAG} ${CHECK_DATARACE_FLAG} ${CHECK_LEAK_FLAG}")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(Glog REQUIRED)
include_directories(${GLOG_INCLUDE_DIRS})


enable_testing()
# 定义获取子目录的宏
macro(SUBDIRLIST result curdir)
  file(
    GLOB children
    RELATIVE ${curdir}
    ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

# 获取子目录
subdirlist(SUBDIRS ${SRC_ROOT})

foreach(d ${SUBDIRS})

  #如果存在测试文件，则生成测试target
  if(EXISTS ${SRC_ROOT}/${d}/${d}_test.cpp)
    add_executable(${d}_test ${SRC_ROOT}/${d}/${d}_test.cpp
                            ${SRC_ROOT}/${d}/${d}.cpp)

    target_link_libraries(${d}_test PUBLIC GTest::GTest GTest::Main)
  
    gtest_discover_tests(${d}_test)
  endif()

endforeach()

add_executable(hello
  src/hello.cpp
)
target_link_libraries(hello glog::glog)

add_executable(measure
  src/measure.cpp
)
target_link_libraries(measure glog::glog)