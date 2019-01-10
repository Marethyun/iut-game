#ifndef IUT_GAME_CELL_H
#define IUT_GAME_CELL_H

#include <string>
#include "Location.h"

class Cell {

public:
    static const char NULCHAR = ' ';

    Cell();
    Cell(const std::string &format);
    Cell(const char character);
    Cell(const std::string &format, const char character);

    const std::string &getFormat() const;
    const char &getCharacter() const;
    
    void setFormat(const std::string &format);
    void setCharacter(const char &character);

    Cell operator+(const Cell & other);

private:
    std::string format;
    char character;

};


#endif
