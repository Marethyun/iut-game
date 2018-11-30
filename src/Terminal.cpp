#include <iostream>
#include "Terminal.h"

void Terminal::clear() {
    std::cout << "\033[H\033[2J";
}

void Terminal::color(std::string color) {
    std::cout << color;
}

// Display a matrix from the current cursor position
void Terminal::matrix(const CellMatrix &cellMatrix) {
    //TODO: Display a matrix
}

void Terminal::moveCursor(const unsigned &x, const unsigned &y) {
    std::cout << "\033[" + std::to_string(x) + ';' + std::to_string(y) + 'H';
}
