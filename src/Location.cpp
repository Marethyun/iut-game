#include "Location.h"

Location::Location(unsigned int x, unsigned int y) : x(x), y(y) {}

unsigned int Location::getX() const {
    return x;
}

void Location::setX(unsigned int x) {
    Location::x = x;
}

unsigned int Location::getY() const {
    return y;
}

void Location::setY(unsigned int y) {
    Location::y = y;
}
