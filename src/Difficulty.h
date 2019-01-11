#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <string>

class Difficulty
{
public:
    Difficulty(const std::string &name,
               const unsigned &height,
               const unsigned &width,
               const unsigned &objectsCount,
               const double &goodObjectProb,
               const unsigned &keysCount,
               const unsigned &grassCount,
               const unsigned &grassSize,
               const unsigned &defaultVision
    );
    
    const std::string name;
    const unsigned height;
    const unsigned width;
    const unsigned objectsCount;
    const double goodObjectProb;
    const unsigned keysCount;
    const unsigned grassCount;
    const unsigned grassSize;
    const unsigned defaultVision;
};

#endif // DIFFICULTY_H
