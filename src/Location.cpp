#include "Location.h"

Location::Location() : x(0), y(0) {}

Location::Location(int x, int y) : x(x), y(y) {}

int Location::getX() const {
    return x;
}

void Location::setX(int x) {
    Location::x = x;
}

int Location::getY() const {
    return y;
}

void Location::setY(int y) {
    Location::y = y;
}

bool Location::operator==(const Location &other) const {
    return other.getX() == this->getX() && other.getY() == this->getY();
}

