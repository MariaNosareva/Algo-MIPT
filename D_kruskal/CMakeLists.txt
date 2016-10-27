cmake_minimum_required(VERSION 3.6)
project(kruskal)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graph.cpp Graph.h DSU.cpp DSU.h)
add_executable(kruskal ${SOURCE_FILES})
target_link_libraries(kruskal ${GTEST_LIBRARIES} pthread)