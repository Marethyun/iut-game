#include "Map.h"
#include "labyrinth/maze.h"
#include "Terminal.h"
#include <iostream>
#include "Color.h"
#include <algorithm>

using namespace std;

Map::Map(unsigned const &height,
         unsigned const &width,
         Location const &beginLocation,
         unsigned const &objectsCount,
         unsigned const &grassCount,
         unsigned const &grassSize,
         unsigned const &keysCount) {
    CMatrix rawMatrix;

    gen_maze(rawMatrix,
             width,
             height,
             beginLocation.getY(),
             beginLocation.getX(),
             objectsCount,
             grassCount,
             grassSize,
             keysCount
    );
    
    this->mapMatrix = Matrix(height, width, Cell(Color::bg_white));
    
    for (unsigned y(0); y < rawMatrix.size(); ++y) {
        CVLine line = rawMatrix[y];
        for (unsigned x(0); x < line.size(); ++x) {
            Location currentLocation(x, y);
            Cell currentCell;
            
            switch (line[x]) {
                case '#':
                    this->wallsLocations.push_back(currentLocation);
                    currentCell.setFormat(Color::bg_black);
                    break;
                case '0':
                    currentCell.setFormat(Color::bg_white);
                    break;
                case 'd':
                    this->beginLocation = currentLocation;
                    break;
                case 'f':
                    this->endLocation = currentLocation;
                    currentCell.setCharacter('.');
                    currentCell.setFormat(Color::bg_red + Color::white);
                    break;
                case '1':
                    this->objectsLocations.push_back(currentLocation);
                    currentCell.setCharacter('%');
                    currentCell.setFormat(Color::blue + Color::bold);
                    break;
                case 'x':
                    this->grassLocations.push_back(currentLocation);
                    currentCell.setCharacter('#');
                    currentCell.setFormat(Color::bg_green + Color::white + Color::bold);
                    break;
                case 'k':
                    this->keysLocations.push_back(currentLocation);
                    currentCell.setCharacter('.');
                    currentCell.setFormat(Color::blue + Color::bold);
                    break;
                default:
                    currentCell.setCharacter('?');
            }
            
            this->mapMatrix.merge(currentLocation, currentCell);
        }
    }
}

bool Map::isObject(const Location &location) const {
    return (std::find(this->objectsLocations.begin(), this->objectsLocations.end(), location) != this->objectsLocations.end());
}

bool Map::isGrass(const Location &location) const {
    return (std::find(this->grassLocations.begin(), this->grassLocations.end(), location) != this->grassLocations.end());    
}

bool Map::isEnd(const Location &location) const {
    return location == this->endLocation;
}

bool Map::isKey(const Location &location) const {
    return (std::find(this->keysLocations.begin(), this->keysLocations.end(), location) != this->keysLocations.end());    
}

bool Map::isWall(const Location &location) const {
    return (std::find(this->wallsLocations.begin(), this->wallsLocations.end(), location) != this->wallsLocations.end());    
}

void Map::claimKey(const Location &location) {
    this->keysLocations.erase(std::find(this->keysLocations.begin(), this->keysLocations.end(), location));
    this->mapMatrix.at(location)->setCharacter(' ');
}

void Map::claimObject(const Location &location) {
    this->objectsLocations.erase(std::find(this->objectsLocations.begin(), this->objectsLocations.end(), location));
    this->mapMatrix.at(location)->setCharacter(' ');
}

Matrix Map::getMap() {
    return this->mapMatrix;
}

Location Map::getBegin() const {
    return this->beginLocation;
}

Location Map::getEnd() const {
    return this->endLocation;
}

unsigned Map::remainingKeys() const {
    return this->keysLocations.size();
}
