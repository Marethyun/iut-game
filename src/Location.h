#ifndef IUT_GAME_LOCATION_H
#define IUT_GAME_LOCATION_H


class Location {
public:
    Location(int x, int y);

    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);

private:
    int x;
    int y;
};


#endif
