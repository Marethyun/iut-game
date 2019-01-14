TEMPLATE = app
CONFIG += console c++11
CONFIG += thread
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    src/exception/GameException.h \
    src/exception/SceneException.h \
    src/maze/maze.h \
    src/scenes/DifficultyScene.h \
    src/scenes/GameScene.h \
    src/scenes/MenuScene.h \
    src/scenes/ResultsScene.h \
    src/scenes/RulesScene.h \
    src/scenes/StoryScene.h \
    src/Cell.h \
    src/Color.h \
    src/Config.h \
    src/Difficulty.h \
    src/Game.h \
    src/Location.h \
    src/Map.h \
    src/Matrix.h \
    src/Player.h \
    src/Remarks.h \
    src/Scene.h \
    src/Terminal.h

SOURCES += \
    src/exception/GameException.cpp \
    src/exception/SceneException.cpp \
    src/maze/maze.cpp \
    src/scenes/DifficultyScene.cpp \
    src/scenes/GameScene.cpp \
    src/scenes/MenuScene.cpp \
    src/scenes/ResultsScene.cpp \
    src/scenes/RulesScene.cpp \
    src/scenes/StoryScene.cpp \
    src/Cell.cpp \
    src/Color.cpp \
    src/Config.cpp \
    src/Difficulty.cpp \
    src/Game.cpp \
    src/Location.cpp \
    src/main.cpp \
    src/Map.cpp \
    src/Matrix.cpp \
    src/Player.cpp \
    src/Remarks.cpp \
    src/Scene.cpp \
    src/Terminal.cpp
