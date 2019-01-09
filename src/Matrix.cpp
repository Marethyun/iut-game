#include <utility>
#include "Matrix.h"
#include <vector>
#include "Cell.h"

#include "Color.h"

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

void Matrix::replace(const unsigned &x, const unsigned &y, Matrix &other) {
    
    for (unsigned i(x), i2(0); i < this->getWidth() && i2 < other.getWidth(); ++i, ++i2) {
        for (unsigned j(y), j2(0); j < this->getHeight() && j2 < other.getHeight(); ++j, ++j2) {
            this->replace(i, j, other.get(i2, j2));
        }
    }
}

void Matrix::replace(const Location &location, Matrix &other) {
    this->replace(location.getX(), location.getY(), other);
}

void Matrix::merge(const unsigned &x, const unsigned &y, const Cell &other) {
    *at(x, y) = *at(x, y) + other;
}

void Matrix::merge(const Location &location, const Cell &other) {
    merge(location.getX(), location.getY(), other);
}

void Matrix::merge(const unsigned &x, const unsigned &y, Matrix &other) {
    for (unsigned i(x), i2(0); i < this->getWidth() && i2 < other.getWidth(); ++i, ++i2) {
        for (unsigned j(y), j2(0); j < this->getHeight() && j2 < other.getHeight(); ++j, ++j2) {
            this->merge(i, j, other.get(i2, j2));
        }
    }
}

void Matrix::text(const unsigned &x, const unsigned &y, const std::string &format, const std::string &text) {
    
    unsigned textWidth = this->getWidth();
    //unsigned textHeight =
    
    Matrix textMatrix(1, text.size(), Cell());
    
    // Height
    unsigned j = 0;
    for (unsigned i(0); i < text.size(); ++i) {
        if (i + 1 == textWidth) ++j;
        textMatrix.replace(i, j, Cell(format, text[i]));
    }
    
    merge(x, y, textMatrix);
}

void Matrix::text(const Location &location, const std::string &format, const std::string &text) {
    this->text((unsigned) location.getX(), (unsigned) location.getY(), format, text);
}

void Matrix::merge(const Location &location, Matrix &other) {
    this->merge(location.getX(), location.getY(), other);
}

bool Matrix::isInBounds(const unsigned &x, const unsigned &y) {
    return x < this->getWidth() && y < this->getHeight();
}

bool Matrix::isInBounds(const Location &location) {
    return isInBounds(location.getX(), location.getY());
}
