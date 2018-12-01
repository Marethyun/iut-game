#ifndef IUT_GAME_TERMINAL_H
#define IUT_GAME_TERMINAL_H


#include <string>
#include "CellMatrix.h"

class Terminal {
public:
    static void clear();
    static void color(std::string string);
    static void matrix(CellMatrix &cellMatrix);
    static void moveCursor(const unsigned &x, const unsigned &y);

    static void saveCursor();
    static void unsaveCursor();
    static void restoreCursor();
    static void cursorUp(const unsigned &count);
    static void cursorDown(const unsigned &count);
    static void cursorBack(const unsigned &count);
    static void cursorForward(const unsigned &count);
};


#endif
