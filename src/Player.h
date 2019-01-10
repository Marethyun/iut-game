#ifndef PLAYER_H
#define PLAYER_H

#include "Location.h"
#include "Cell.h"

class Player
{
public:
    Player(const Location &location, const Cell &appearance, const unsigned &vision);
    
    Location getLocation();
    Cell getAppearance();
    unsigned getVision();
    
    void setLocation(const Location &location);
    void setAppearance(const Cell &appearance);
    void setVision(const unsigned &vision);
    
private:
    Location location;
    Cell appearance;
    unsigned vision;
};

#endif // PLAYER_H
