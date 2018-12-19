#include <iostream>
#include "Color.h"

#include "Matrix.h"
#include "Terminal.h"

#include <unistd.h>

using namespace std;

int main() {
//    Cell c1 = Cell(Color::red, '5');

    Matrix m = Matrix(5, 10, Cell(Color::bg_lightgray));

//    for (unsigned i(0); i < 5; ++i){
//        m.merge(i, 1, Cell(Color::bg_black));

//        m.merge(i, 3, Cell(Color::bg_black));
//    }

//    m.merge(3, 3, Cell(Color::bg_yellow, '.'));

//    m.merge(0, 0, Cell(Color::red + Color::bold, '&'));

//    m.merge(4, 0, Cell(Color::magenta, '1'));
//    m.merge(2, 2, Cell(Color::magenta, '1'));

//    m.merge(0, 2, Cell(Color::yellow, '.'));

//    m.merge(0, 4, Cell(Color::bg_green));

    m.merge(0, 1, Cell('9'));

    Terminal::matrix(m);

    return 0;
}
