cmake_minimum_required(VERSION 3.5)
project(SecondStastics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(BUILD_GTEST ON)


add_subdirectory(Tests)
add_subdirectory(Main)
add_subdirectory(SegmentTree)