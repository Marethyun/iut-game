cmake_minimum_required(VERSION 3.0)
project(iut_game)

set(WINDOWS TRUE)

set(SOURCES src/exception/GameException.cpp src/exception/SceneException.cpp src/maze/maze.cpp src/scenes/DifficultyScene.cpp src/scenes/GameScene.cpp src/scenes/MenuScene.cpp src/scenes/ResultsScene.cpp src/scenes/RulesScene.cpp src/scenes/StoryScene.cpp src/Cell.cpp src/Color.cpp src/Config.cpp src/Difficulty.cpp src/Game.cpp src/Location.cpp src/main.cpp src/Map.cpp src/Matrix.cpp src/Player.cpp src/Remarks.cpp src/Scene.cpp src/Terminal.cpp)

add_executable(iut_game ${SOURCES})

if (WINDOWS)
    target_compile_definitions(iut_game PRIVATE WINDOWS=1)
endif()