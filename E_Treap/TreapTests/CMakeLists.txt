cmake_minimum_required(VERSION 3.5)
add_executable(TreapTests tests.cpp)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

target_link_libraries(TreapTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(TreapTests TreapLib)