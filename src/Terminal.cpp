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

    for (unsigned i(0); i < cellMatrix.getHeight(); ++i) {

//        saveCursor();

        for (unsigned j(0); j < cellMatrix.getWidth(); ++j) {
            Cell cell = cellMatrix.get(i, j);

            cout << cell.getBackgroundColor();
            cout << cell.getColor();
            cout << cell.getCharacter();
            cout << Color::reset;

            // TODO: Refactor
            cerr << cell.getBackgroundColor() << cell.getColor() << cell.getCharacter();
        }

        cout << endl;

        // Place cursor at the beginning of the next line
//        restoreCursor();
//        cursorDown(1);
    }
}

void Terminal::moveCursor(const unsigned &x, const unsigned &y) {
    std::cout << "\033[" + std::to_string(x) + ';' + std::to_string(y) + 'H';
}
