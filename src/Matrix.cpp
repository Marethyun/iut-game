#include <utility>
#include "Matrix.h"
#include <vector>
#include "Cell.h"

using namespace std;

Matrix::Matrix(const unsigned int &height, const unsigned int &width, const Cell &defaultElem) : height(height), width(width) {

    this->matrix = vector<vector<Cell>>(width);

    for (unsigned i(0); i < this->matrix.size(); ++i) {
        vector<Cell> line(height);

        for (unsigned j(0); j < line.size(); ++j) {
            line[j] = defaultElem;
        }

        this->matrix[i] = line;
    }
}

Matrix::Matrix(const vector<vector<Cell>> &matrix) : matrix(matrix) {}

unsigned int Matrix::getHeight() const {
    return height;
}

unsigned int Matrix::getWidth() const {
    return width;
}

Cell& Matrix::get(const unsigned &x, const unsigned &y) {
    return *at(x, y);
}

Cell& Matrix::get(const Location &location) {
    return *at(location.getX(), location.getY());
}

Cell* Matrix::at(const unsigned &x, const unsigned &y) {
    return &matrix[x][y];
}

Cell* Matrix::at(const Location &location) {
    return at(location.getX(), location.getY());
}

void Matrix::replace(const unsigned &x, const unsigned &y, const Cell &other) {
    *at(x, y) = other;
}

void Matrix::replace(const Location &location, const Cell &other) {
    replace(location.getX(), location.getY(), other);
}

void Matrix::merge(const unsigned &x, const unsigned &y, const Cell &other) {
    *at(x, y) = *at(x, y) + other;
}

void Matrix::merge(const Location &location, const Cell &other) {
    merge(location.getX(), location.getY(), other);
}

bool Matrix::isInBounds(const unsigned &x, const unsigned &y) {
    return x < this->getWidth() && y < this->getHeight();
}

bool Matrix::isInBounds(const Location &location) {
    return isInBounds(location.getX(), location.getY());
}

//Matrix Matrix::operator+(const Matrix &other){
//    if (this->getHeight() == other.getHeight() && this->getWidth() == other.getWidth()) {

//    }
//}
