#ifndef DIFFICULTY_H
#define DIFFICULTY_H

class Difficulty
{
public:
    Difficulty(const unsigned &height,
               const unsigned &width,
               const unsigned &objectsCount,
               const double &goodObjectProb,
               const unsigned &keysCount,
               const unsigned &grassCount,
               const unsigned &grassSize,
               const unsigned &defaultVision
    );

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
