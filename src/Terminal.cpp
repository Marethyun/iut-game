#include <iostream>
#include "Terminal.h"
#include "Color.h"
#include <unistd.h>

#ifdef WINDOWS
    #include "conio.h"
#else
    #include <termios.h>
#endif

using namespace std;

void Terminal::clear() {
    #ifdef WINDOWS
        // Pas de clrscr sous MINGW
        system("cls");
    #else
        printf("\033[2J\033[H");
    #endif
}

void Terminal::color(std::string color) {
    std::cout << color;
}

// Display a matrix from the current cursor position
void Terminal::matrix(Matrix &cellMatrix) {
    //TODO: Display a matrix

    for (unsigned i(0); i < cellMatrix.getHeight(); ++i) {

        saveCursor();

        for (unsigned j(0); j < cellMatrix.getWidth(); ++j) {
            Cell cell = cellMatrix.get(j, i);

            cout << cell.getFormat() << cell.getCharacter() << Color::reset << std::flush;
        }

        // Place cursor at the beginning of the next line
        restoreCursor();
        cursorDown(1);
    }
    
    unsaveCursor();
    cursorDown(1);
    cout << std::flush;
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

#ifdef WINDOWS
char Terminal::getch() {
    return ::getch();
}
#else
// Source: https://code.i-harness.com/fr/q/66fe4
char Terminal::getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
            perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror ("tcsetattr ~ICANON");
    return (buf);
}
#endif
