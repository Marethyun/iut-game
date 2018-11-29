#include "Cell.h"
#include "Color.h"

Cell::Cell() : color(Color::black), backgroundColor(Color::bg_black), character(' ') {}

Cell::Cell(const std::string &color, const std::string &backgroundColor, char character)
        : color(color), backgroundColor(backgroundColor), character(character) {}

const std::string &Cell::getColor() const {
    return color;
}

const std::string &Cell::getBackgroundColor() const {
    return backgroundColor;
}

char Cell::getCharacter() const {
    return character;
}
