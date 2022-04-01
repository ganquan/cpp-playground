# CMakeLists.txt

cmake_minimum_required(VERSION "3.17")

project(cpp-playground)

set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_CXX_STANDARD 17)

# 配置gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

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

    target_link_libraries(${d}_test gtest_main gmock_main)

    gtest_discover_tests(${d}_test)
  endif()

endforeach()
