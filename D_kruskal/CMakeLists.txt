cmake_minimum_required(VERSION 3.6)
project(kruskal)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(BUILD_GTEST ON)


add_subdirectory(files_for_tests)
add_subdirectory(kruskal_main)
add_subdirectory(source)


