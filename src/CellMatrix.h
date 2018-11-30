#ifndef IUT_GAME_CELLMATRIX_H
#define IUT_GAME_CELLMATRIX_H

#include <vector>
#include <string>
#include "Cell.h"

class CellMatrix {
public:
    CellMatrix(const unsigned int &height, const unsigned int &width, const Cell &defaultCell);
    CellMatrix(const std::vector<std::vector<Cell>> &matrix);

    unsigned int getHeight() const;
    unsigned int getWidth() const;

    Cell get(const unsigned &x, const unsigned &y) const;
    Cell get(Location location);

private:
    unsigned height;
    unsigned width;
    std::vector<std::vector<Cell>> matrix;
};


#endif
