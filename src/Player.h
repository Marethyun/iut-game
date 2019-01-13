#ifndef PLAYER_H
#define PLAYER_H

/**
 * @file Player.h
 * @brief Header for the Player class
 * @author Ange Bacci
 */

#include "Location.h"
#include "Cell.h"

/**
 * @class Player
 * @brief Represents a player
 *
 * @see GameScene
 */
class Player
{
public:
    /**
     * @brief The full constructor
     *
     * @param location The initial player Location
     * @param appearance The player appearance
     * @param vision The initial player vision
     */
    Player(const Location &location, const Cell &appearance, const unsigned &vision);

    /**
     * @brief Getter for the Location
     *
     * @return The player @ref #location
     */
    Location getLocation();

    /**
     * @brief Getter for the appearance
     * @return The player @ref #appearance
     */
    Cell getAppearance();

    /**
     * @brief Getter for the vision
     * @return The player @ref #vision
     */
    unsigned getVision();

    /**
     * @brief Setter for the location
     * @param location The player Location
     */
    void setLocation(const Location &location);

    /**
     * @brief Setter for the appearance
     * @param appearance The appearance
     */
    void setAppearance(const Cell &appearance);

    /**
     * @brief Setter for the visison
     * @param vision The vision
     */
    void setVision(const unsigned &vision);
    
private:
    /**
     * @brief The player location in the labyrinth
     */
    Location location;

    /**
     * @brief The player appearance, a Cell.
     */
    Cell appearance;

    /**
     * @brief The player vision.
     */
    unsigned vision;
};

#endif // PLAYER_H
