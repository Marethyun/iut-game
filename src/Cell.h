#ifndef IUT_GAME_CELL_H
#define IUT_GAME_CELL_H

#include <string>
#include "Location.h"

class Cell {

public:
    Cell();
    Cell(const std::string &color, const std::string &backgroundColor, char character);

    const std::string &getColor() const;

    const std::string &getBackgroundColor() const;

    char getCharacter() const;

private:
    std::string color;
    std::string backgroundColor;
    char character;

};


#endif
