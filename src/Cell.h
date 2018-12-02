#ifndef IUT_GAME_CELL_H
#define IUT_GAME_CELL_H

#include <string>
#include "Location.h"

class Cell {

public:
    Cell();
    Cell(const std::string &format, char character);

    const std::string &getFormat() const;
    char getCharacter() const;

    Cell &operator=(const Cell & other);

private:
    std::string format;
    char character;

};


#endif
