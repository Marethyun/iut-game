cmake_minimum_required(VERSION 3.12)
project(iut_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(iut_game src/main.cpp src/Color.cpp src/Color.h src/Terminal.cpp src/Terminal.h src/CellMatrix.cpp src/CellMatrix.h src/Cell.cpp src/Cell.h src/Location.cpp src/Location.h src/Scene.cpp src/Scene.h src/Game.cpp src/Game.h src/exception/GameException.cpp src/exception/GameException.h src/exception/SceneException.cpp src/exception/SceneException.h)