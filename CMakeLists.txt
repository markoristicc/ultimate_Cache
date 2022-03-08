cmake_minimum_required(VERSION 3.12)
project(ultimate_Cache)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        main

        caches/cache.h
        caches/MRU.cpp
        caches/MRU.h
        caches/LFU.cpp
        caches/LFU.h
        caches/LRU.cpp
        caches/LRU.h
        caches/RR.cpp
        caches/RR.h
        caches/RLRU.cpp
        caches/RLRU.h
        caches/MRU.cpp
        caches/MRU.h
        caches/ULT.cpp
        caches/ULT.h

        caches/CMB.cpp
        caches/CMB.h
        caches/CMB2.cpp
        caches/CMB2.h

        testers/tester.h
        testers/impl_tester.h
        testers/impl_tester.cpp
        testers/belady_tester.h
        testers/belady_tester.cpp

        tests.cpp
        tests.h

        main.cpp
)
