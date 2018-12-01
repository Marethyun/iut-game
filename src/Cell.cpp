#include "Cell.h"
#include "Color.h"

Cell::Cell() : color(Color::green), backgroundColor(Color::bg_blue), character('X') {}

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

Cell &Cell::operator=(const Cell &other) {

    this->color = other.getColor();
    this->backgroundColor = other.getBackgroundColor();
    this->character = other.getCharacter();

    return *this;
}

