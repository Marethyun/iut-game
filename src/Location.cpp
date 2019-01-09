#include "Location.h"

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
