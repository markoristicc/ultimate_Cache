cmake_minimum_required(VERSION 3.22)
project(ultimate_Cache)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        tests

        caches/cache.h
        caches/LRU.cpp
        caches/LRU.h
        caches/RR.cpp
        caches/RR.h
        caches/RLRU.cpp
        caches/RLRU.h

        testers/tester.h
        testers/impl_tester.h
        testers/impl_tester.cpp
        testers/belady_tester.h
        testers/belady_tester.cpp

        tests.cpp
)
