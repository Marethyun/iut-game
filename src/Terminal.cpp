#include <iostream>
#include "Terminal.h"
#include "Color.h"

using namespace std;

void Terminal::clear() {
    //
    printf("\033[2J\033[H");
}

void Terminal::color(std::string color) {
    std::cout << color;
}

// Display a matrix from the current cursor position
void Terminal::matrix(CellMatrix &cellMatrix) {
    //TODO: Display a matrix

    for (unsigned i(0); i < cellMatrix.getHeight(); ++i) {

        saveCursor();

        for (unsigned j(0); j < cellMatrix.getWidth(); ++j) {
            Cell cell = cellMatrix.get(i, j);

            cout << cell.getFormat() << cell.getCharacter() << Color::reset;
        }

        // Place cursor at the beginning of the next line
        restoreCursor();
        cursorDown(1);
    }
}

void Terminal::cell(const Cell &cel) {
    cout << cel.getFormat() << cel.getCharacter() << Color::reset;
}

void Terminal::moveCursor(const unsigned &x, const unsigned &y) {
    std::cout << "\033[" + std::to_string(x) + ';' + std::to_string(y) + 'H';
}

void Terminal::saveCursor() {
    std::cout << "\033[s";
}
void Terminal::unsaveCursor() {
    std::cout << "\033[u";
}
void Terminal::restoreCursor() {
    std::cout << "\0338";
}
void Terminal::cursorUp(const unsigned &count) {
    std::cout << "\033[" + std::to_string(count) + "A";
}
void Terminal::cursorDown(const unsigned &count) {
    std::cout << "\033[" + std::to_string(count) + "B";
}
void Terminal::cursorForward(const unsigned &count) {
    std::cout << "\033[" + std::to_string(count) + "C";
}
void Terminal::cursorBack(const unsigned &count) {
    std::cout << "\033[" + std::to_string(count) + "D";
}