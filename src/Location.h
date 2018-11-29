#ifndef IUT_GAME_LOCATION_H
#define IUT_GAME_LOCATION_H


class Location {
public:
    Location(unsigned int x, unsigned int y);

    unsigned int getX() const;
    void setX(unsigned int x);
    unsigned int getY() const;
    void setY(unsigned int y);

private:
    unsigned x;
    unsigned y;
};


#endif
