#include <iostream>
#include "CellMatrix.h"
#include "Color.h"
#include "Terminal.h"

using namespace std;

int main() {
    CellMatrix matrix = CellMatrix(10, 10, Cell("GREEN", "BG_BLUE", 'X'));

    Terminal::matrix(matrix);
    return 0;
}