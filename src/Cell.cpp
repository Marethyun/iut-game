#include "Cell.h"
#include "Color.h"

#include <iostream>

// Blank cell
Cell::Cell() : format(""), character(NULCHAR) {}

Cell::Cell(const std::string &format) : format(format), character(NULCHAR) {}

Cell::Cell(const char character) : format(""), character(character) {}

Cell::Cell(const std::string &format, const char character) : format(format), character(character) {}

const std::string &Cell::getFormat() const {
    return format;
}

const char& Cell::getCharacter() const {
    return character;
}

Cell Cell::operator+(const Cell &other) {
    return Cell(this->getFormat() + other.getFormat(), other.getCharacter() == NULCHAR ? this->getCharacter() : other.getCharacter());
}
