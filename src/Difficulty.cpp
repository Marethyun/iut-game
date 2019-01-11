#include "Difficulty.h"

Difficulty::Difficulty(const std::string &name,
                       const unsigned &height,
                       const unsigned &width,
                       const unsigned &objectsCount,
                       const double &goodObjectProb,
                       const unsigned &keysCount,
                       const unsigned &grassCount,
                       const unsigned &grassSize,
                       const unsigned &defaultVision
) : name(name),
    height(height),
    width(width),
    objectsCount(objectsCount),
    goodObjectProb(goodObjectProb),
    keysCount(keysCount),
    grassCount(grassCount),
    grassSize(grassSize),
    defaultVision(defaultVision)
{

}
