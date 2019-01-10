#ifndef MAP_H
#define MAP_H

#include "Matrix.h"
#include "labyrinth/labyrinth.h"
#include <vector>

class Map
{
public:
    Map(unsigned const &height,
        unsigned const &width,
        Location const &beginLocation,
        unsigned const &objectsCount,
        unsigned const &grassCount,
        unsigned const &grassSize,
        unsigned const &keysCount
    );
    
    bool isObject(const Location &location) const;
    bool isGrass(const Location &location) const;
    bool isEnd(const Location &location) const;
    bool isKey(const Location &location) const;
    bool isWall(const Location &location) const;
    
    void claimKey(const Location &location);
    void claimObject(const Location &location);
   
    Matrix getMap();
    Location getBegin() const;
    Location getEnd() const;
    
    unsigned remainingKeys() const;
    
private:
    Matrix mapMatrix;
    Location beginLocation;
    Location endLocation;
    std::vector<Location> wallsLocations;
    std::vector<Location> objectsLocations;
    std::vector<Location> grassLocations;
    std::vector<Location> keysLocations;
};

#endif // MAP_H
