#include <utility>
#include "Matrix.h"
#include <vector>
#include "Cell.h"
#include <algorithm>
#include "Color.h"
#include <sstream>
#include <math.h>
#include <cassert>

using namespace std;

Matrix::Matrix() : height(0), width(0), matrix(vector<vector<Cell>>()) {}

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

void Matrix::merge(const Location &location, Matrix &other) {
    this->merge(location.getX(), location.getY(), other);
}

void Matrix::text(const unsigned &x, const unsigned &y, const unsigned &width, const std::string &format, const std::string &text) {
    string wrappedText = wrap(text, width);
    
    long textHeight = ceil((double) text.size() / (double) width) * this->height;
    
    Matrix textMatrix(textHeight, width, Cell());
    
    for (unsigned i(0), mx(0), my(0); i < wrappedText.size(); ++i) {
        if (wrappedText[i] == '\n') {
            ++my;
            mx = 0;
            continue;
        }
        
        textMatrix.replace(mx, my, Cell(format, wrappedText[i]));
        ++mx;
    }
    
    this->merge(x, y, textMatrix);
}

void Matrix::text(const Location &location, const unsigned &width, const std::string &format, const std::string &text) {
    this->text((unsigned) location.getX(), (unsigned) location.getY(), width, format, text);
}

void Matrix::text(const unsigned &x, const unsigned &y, const std::string &format, const std::string &text) {
    this->text(x, y, this->getWidth() - x, format, text);
}

void Matrix::text(const Location &location, const std::string &format, const std::string &text) {
    this->text(location, this->getWidth() - location.getX(), format, text);
}

Matrix Matrix::crop(const int &x1, const int &y1, const int &x2, const int &y2, const Cell &defaultCell) {
    
    assert(x1 < x2 && y1 < y2);
    
    Matrix cropped(x2 + 1 - x1, y2 + 1 - y1, defaultCell);
    
    bool jj = x1 < (int) this->getWidth();
    
    for (int x(0), matX(x1); matX < (int) this->getWidth() && x < (int) cropped.getWidth(); ++matX, ++x) {
        for (int y(0), matY(y1); matY < (int) this->getHeight() && y < (int) cropped.getHeight(); ++matY, ++y) {
            if (isInBounds(matX, matY)) {
                cropped.replace(x, y, this->get(matX, matY));
            }
        }
    }
    
    return cropped;
}

Matrix Matrix::crop(const Location &loc1, const Location &loc2, const Cell &defaultCell) {
    return this->crop(loc1.getX(), loc1.getY(), loc2.getX(), loc2.getY(), defaultCell);
}

Location Matrix::center() {
    return Location(ceil((double) this->getWidth() / 2) - 1, ceil((double) this->getHeight() / 2) - 1);
}

bool Matrix::isInBounds(const int &x, const int &y) {
    
    if (x < 0 || y < 0) return false;
    return (unsigned) x < this->getWidth() && (unsigned) y < this->getHeight();
}

bool Matrix::isInBounds(const Location &location) {
    return isInBounds(location.getX(), location.getY());
}

std::string Matrix::wrap(std::string text, unsigned width) {
    // split the text
    vector<string> splitted;
    istringstream iss(text);
    string temp;
    while (getline(iss, temp, '\n')) {
        splitted.push_back(temp);
    }

    bool wrapped = true;
    for (const string &s : splitted) {
        if (s.size() > width) wrapped = false;
    }

    if (wrapped) {
        return text;
    }

    string ret;

    for (string s : splitted) {
        if (s.size() > width) {
            if (s[width] == ' ') {
                ret += s.substr(0, width) + '\n' + s.substr(width + 1, s.size());
            } else {
                unsigned i = width - 1;
                for (; i > 0; --i) {
                    if (s[i] == ' ') break;
                }

                if (i == 0) {
                    ret += s.substr(0, width) + '\n' + s.substr(width, s.size());
                } else {
                    ret += s.substr(0, i) + '\n' + s.substr(i + 1, s.size());
                }
            }
        } else {
            ret += s + '\n';
        }
    }

    return wrap(ret, width);
}
