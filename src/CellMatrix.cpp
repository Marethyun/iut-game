#include <utility>
#include "CellMatrix.h"
#include <vector>

using namespace std;

CellMatrix::CellMatrix(const unsigned int &height, const unsigned int &width, const Cell &defaultCell) : height(height), width(width) {

    this->matrix = vector<vector<Cell>>(height);

    for (unsigned i(0); i < this->matrix.size(); ++i) {
        vector<Cell> line(width);

        for (unsigned j(0); j < line.size(); ++j) {
            line[j] = defaultCell;
        }

        this->matrix[i] = line;
    }
}

CellMatrix::CellMatrix(const vector<vector<Cell>> &matrix) : matrix(matrix) {}

unsigned int CellMatrix::getHeight() const {
    return height;
}

unsigned int CellMatrix::getWidth() const {
    return width;
}

Cell& CellMatrix::get(const unsigned &x, const unsigned &y) {
    return matrix[x][y];
}

Cell& CellMatrix::get(const Location &location) {
    return get(location.getX(), location.getY());
}

Cell* CellMatrix::at(const unsigned &x, const unsigned &y) {
    return &matrix[x][y];
}

Cell* CellMatrix::at(const Location &location) {
    return at(location.getX(), location.getY());
}
