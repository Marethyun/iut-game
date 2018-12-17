#include <iostream>
#include "Color.h"

#include "CellMatrix.h"
#include "Terminal.h"

#include <unistd.h>

using namespace std;

int main() {

//    CellMatrix* matrix = new CellMatrix(10, 10, Cell(Color::reset, '#'));

//    *matrix->at(Location(0, 4)) = Cell(Color::red + Color::bg_blue, '0');

//    Terminal::moveCursor(10, 10);
//    Terminal::matrix(*matrix);

    while (true) {
        usleep(1000000);
        cout << "Hello" << endl;
    }

//    Terminal::clear();

//    Terminal::cell(Cell(Color::bg_red, ' '));

    char c;
    cin >> c;

    return 0;
}
