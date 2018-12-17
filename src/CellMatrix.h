#ifndef IUT_GAME_CELLMATRIX_H
#define IUT_GAME_CELLMATRIX_H

#include <vector>
#include <string>

#include "Location.h"

// C Must be a Cell or a base of Cell
template <typename C> class CellMatrix {
public:
    CellMatrix(const unsigned int &height, const unsigned int &width, const C &defaultElem);
    CellMatrix(const std::vector<std::vector<C>> &matrix);

    unsigned int getHeight() const;
    unsigned int getWidth() const;

    C & get(const unsigned &x, const unsigned &y);
    C & get(const Location &location);

    C * at(const unsigned &x, const unsigned &y);
    C * at(const Location &location);

private:
    unsigned height;
    unsigned width;
    std::vector<std::vector<C>> matrix;
};


#endif
