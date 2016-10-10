cmake_minimum_required(VERSION 3.6)
project(trade_arbitrage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SalesGraph.cpp SalesGraph.h)
add_executable(trade_arbitrage ${SOURCE_FILES})