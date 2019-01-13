#ifndef IUT_GAME_LOCATION_H
#define IUT_GAME_LOCATION_H

/**
 * @file Location.h
 * @brief Header for the Location class
 * @author Ange Bacci
 */


/**
 * @class Location
 * @brief A plain old object, representing coordinates (or a location) in a matrix
 *
 * Locations coordinates may be negative, because of the bounds check
 *
 * @see Matrix
 */
class Location {
public:
    /**
     * @brief The default constructor
     *
     * Locations @ref #x and @ref #y are set to 0 by default
     */
    Location();

    /**
     * The full constructor, builds a Location with its coordinates
     * @param x The x-coordinate
     * @param y The y-coordinate
     */
    Location(int x, int y);

    /**
     * @brief Getter for the x-coordinate
     * @return The Location @ref #x
     */
    int getX() const;

    /**
     * @brief Setter for the x-coordinate
     * @param x The x-coordinate
     */
    void setX(int x);

    /**
     * @brief Getter for the y-coordinate
     * @return The Location @ref #y
     */
    int getY() const;

    /**
     * @brief Setter for the y-coordinate
     * @param y The y-coordinate
     */
    void setY(int y);

    /**
     * @brief The comparison operator
     *
     * Compare the x and y coordinates
     *
     * @param other The other Location
     * @return true if the Locations are equals, false otherwise
     */
    bool operator==(const Location &other) const;
    
private:
    /**
     * @brief The x-coordinate
     */
    int x;

    /**
     * @brief The y-coordinate
     */
    int y;
};


#endif
