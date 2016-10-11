cmake_minimum_required(VERSION 3.6)
project(pyatnashki)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Field.cpp Field.h PuzzleSolver.cpp PuzzleSolver.h)
add_executable(pyatnashki ${SOURCE_FILES})