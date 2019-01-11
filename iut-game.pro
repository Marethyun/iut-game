TEMPLATE = app
CONFIG += console c++11
CONFIG += thread
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/exception/GameException.cpp \
    src/exception/SceneException.cpp \
    src/Cell.cpp \
    src/Color.cpp \
    src/Game.cpp \
    src/Location.cpp \
    src/main.cpp \
    src/Scene.cpp \
    src/Terminal.cpp \
    src/Matrix.cpp \
    src/scenes/GameScene.cpp \
    src/labyrinth/labyrinth.cpp \
    src/Map.cpp \
    src/Player.cpp \
    src/scenes/MenuScene.cpp \
    src/scenes/DifficultyScene.cpp \
    src/Difficulty.cpp \
    src/scenes/ResultsScene.cpp \
    src/Remarks.cpp

HEADERS += \
    src/exception/GameException.h \
    src/exception/SceneException.h \
    src/Cell.h \
    src/Color.h \
    src/Game.h \
    src/Location.h \
    src/Scene.h \
    src/Terminal.h \
    src/Matrix.h \
    src/testscene.h \
    src/scenes/GameScene.h \
    src/labyrinth/labyrinth.h \
    src/Map.h \
    src/Player.h \
    src/scenes/MenuScene.h \
    src/scenes/DifficultyScene.h \
    src/Difficulty.h \
    src/scenes/ResultsScene.h \
    src/Remarks.h
