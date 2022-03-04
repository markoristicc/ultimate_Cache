cmake_minimum_required(VERSION 3.22)
project(ultimate_Cache)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LRUtest
        LRU.cpp
        LRU.h
        LRUtest.cpp)
