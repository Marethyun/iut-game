#include "Cell.h"
#include "Color.h"

// Blank cell
Cell::Cell() : format(""), character(' ') {}

Cell::Cell(const std::string &format, char character)
        : format(format), character(character) {}

const std::string &Cell::getFormat() const {
    return format;
}

char Cell::getCharacter() const {
    return character;
}

Cell &Cell::operator=(const Cell &other) {

    this->format = other.getFormat();
    this->character = other.getCharacter();

    return *this;
}

