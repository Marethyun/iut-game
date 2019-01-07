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
    src/Matrix.cpp

HEADERS += \
    src/exception/GameException.h \
    src/exception/SceneException.h \
    src/external/bitmap_image.hpp \
    src/Cell.h \
    src/Color.h \
    src/Game.h \
    src/Location.h \
    src/Scene.h \
    src/Terminal.h \
    src/Matrix.h
