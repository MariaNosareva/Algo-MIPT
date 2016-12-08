cmake_minimum_required(VERSION 3.5)
project(trade_arbitrage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(BUILD_GTEST ON)

add_subdirectory(A_Tests)
add_subdirectory(A_Main)
add_subdirectory(GraphLib)
