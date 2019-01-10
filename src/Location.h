#ifndef IUT_GAME_LOCATION_H
#define IUT_GAME_LOCATION_H


class Location {
public:
    Location();
    Location(int x, int y);

    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    
    bool operator==(const Location &other) const;
    
private:
    int x;
    int y;
};


#endif
