cmake_minimum_required(VERSION 3.12)
project(iut_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(iut_game src/main.cpp src/Color.cpp src/Color.h src/Terminal.cpp src/Terminal.h src/CellMatrix.cpp src/CellMatrix.h src/Cell.cpp src/Cell.h src/Location.cpp src/Location.h)