#include <utility>
#include "CellMatrix.h"
#include <vector>

using namespace std;

template <typename C> CellMatrix<C>::CellMatrix(const unsigned int &height, const unsigned int &width, const C &defaultCell) : height(height), width(width) {

    this->matrix = vector<vector<C>>(height);

    for (unsigned i(0); i < this->matrix.size(); ++i) {
        vector<C> line(width);

        for (unsigned j(0); j < line.size(); ++j) {
            line[j] = defaultCell;
        }

        this->matrix[i] = line;
    }
}

template <typename C> CellMatrix<C>::CellMatrix(const vector<vector<C>> &matrix) : matrix(matrix) {}

template <typename C> unsigned int CellMatrix<C>::getHeight() const {
    return height;
}

template <typename C> unsigned int CellMatrix<C>::getWidth() const {
    return width;
}

template <typename C> C& CellMatrix<C>::get(const unsigned &x, const unsigned &y) {
    return *at(x, y);
}

template <typename C> C& CellMatrix<C>::get(const Location &location) {
    return *at(location.getX(), location.getY());
}

template <typename C> C* CellMatrix<C>::at(const unsigned &x, const unsigned &y) {
    return &matrix[x][y];
}

template <typename C> C* CellMatrix<C>::at(const Location &location) {
    return at(location.getX(), location.getY());
}
