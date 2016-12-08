cmake_minimum_required(VERSION 3.6)
project(pyatnashki)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(BUILD_GTEST ON)


add_subdirectory(B_Tests)
add_subdirectory(B_Main)
add_subdirectory(SolverLib)