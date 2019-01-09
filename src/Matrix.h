/**
 *  @file 
 */ 

#ifndef IUT_GAME_MATRIX_H
#define IUT_GAME_MATRIX_H

#include <vector>
#include <string>
#include "Location.h"
#include "Cell.h"

class Matrix {
public:
    Matrix(const unsigned int &height, const unsigned int &width, const Cell &defaultElem);
    Matrix(const std::vector<std::vector<Cell>> &matrix);
    
    unsigned int getHeight() const;
    unsigned int getWidth() const;

    Cell & get(const unsigned &x, const unsigned &y);
    Cell & get(const Location &location);

    Cell * at(const unsigned &x, const unsigned &y);
    Cell * at(const Location &location);

    void replace(const unsigned &x, const unsigned &y, const Cell &other);
    void replace(const Location &location, const Cell &other);
    void replace(const unsigned &x, const unsigned &y, Matrix &other);
    void replace(const Location &location, Matrix &other);

    void merge(const unsigned &x, const unsigned &y, const Cell &other);
    void merge(const Location &location, const Cell &other);
    void merge(const unsigned &x, const unsigned &y, Matrix &other);
    void merge(const Location &location, Matrix &other);
    
    void text(const unsigned &x, const unsigned &y, const std::string &format, const std::string &text);
    void text(const Location &location, const std::string &format, const std::string &text);
    
    bool isInBounds(const unsigned &x, const unsigned &y);
    bool isInBounds(const Location &location);

private:
    unsigned height;
    unsigned width;
    std::vector<std::vector<Cell>> matrix;
};

#endif
