cmake_minimum_required(VERSION 3.6)
add_executable(Tests tests.cpp)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

target_link_libraries(Tests ${GTEST_LIBRARIES} pthread)
target_link_libraries(Tests Prefix)
