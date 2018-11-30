#ifndef IUT_GAME_TERMINAL_H
#define IUT_GAME_TERMINAL_H


#include <string>
#include "CellMatrix.h"

class Terminal {
public:
    static void clear();
    static void color(std::string string);
    static void matrix(const CellMatrix &cellMatrix);
    static void moveCursor(const unsigned &x, const unsigned &y);
};


#endif
