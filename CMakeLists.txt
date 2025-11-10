cmake_minimum_required(VERSION 3.31)
project(Roulette)

set(CMAKE_CXX_STANDARD 20)

add_executable(Roulette
        server/server.cpp
        color.cpp
        color.h
        outcome.cpp
        outcome.h
        Utility/utility.cpp
        Utility/utility.h)
