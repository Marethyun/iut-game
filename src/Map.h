#ifndef MAP_H
#define MAP_H

/**
 * @file Map.h
 * @brief Header for the Map class
 * @author Ange Bacci
 */

#include "Matrix.h"
#include "maze/maze.h"
#include <vector>

/**
 * @class Map
 * @brief Represents a game map, a maze
 *
 * NOTE: I admit that the way i chose to determine where objects, grasses, walls, and keys are is the worst way.
 * I should have used the raw generated maze instead of storing the coordinates one by one in multiple vectors, because
 * when it comes to search for walls in huge mazes, it may be very slow.
 * I do not want to change anything at this stage anyway.
 *
 * @see GameScene
 */
class Map
{
public:
    /**
     * @brief The full constructor
     *
     * @param height The maze height
     * @param width The maze height
     * @param beginLocation The maze start location
     * @param objectsCount The count of objects in the maze
     * @param grassCount The count of grass plots
     * @param grassSize The size of the grass plots
     * @param keysCount The count of the keys
     */
    Map(unsigned const &height,
        unsigned const &width,
        Location const &beginLocation,
        unsigned const &objectsCount,
        unsigned const &grassCount,
        unsigned const &grassSize,
        unsigned const &keysCount
    );

    /**
     * @brief Check if there is an object at the location
     * @param location The location
     * @return true if there is an object, false otherwise
     */
    bool isObject(const Location &location) const;

    /**
     * @brief Check if there is a grass plot at the location
     * @param location The location
     * @return true if there is a grass plot, false otherwise
     */
    bool isGrass(const Location &location) const;

    /**
     * @brief Check if the end is as the location
     * @param location The location
     * @return true if there is the end, false otherwise
     */
    bool isEnd(const Location &location) const;

    /**
     * @brief Check if there is a key at the location
     * @param location The location
     * @return true if there is a key, false otherwise
     */
    bool isKey(const Location &location) const;

    /**
     * @brief Check if there is a wall at the location
     * @param location The location
     * @return true if there is a wall
     */
    bool isWall(const Location &location) const;

    /**
     * @brief Claims a key
     * @param location The location of the key to claim
     */
    void claimKey(const Location &location);

    /**
     * @brief Claims an object
     * @param location The location of the object to claim
     */
    void claimObject(const Location &location);

    /**
     * @brief Getter for the raw Matrix map
     * @return The @ref #mapMatrix
     */
    Matrix getMap();

    /**
     * @brief Getter for the maze start Location
     * @return The @ref #beginLocation
     */
    Location getBegin() const;

    /**
     * @brief Getter for the maze end Location
     * @return The @ref #endLocation
     */
    Location getEnd() const;

    /**
     * @brief Calculates the remaining keys to claim
     * @return How many keys are remaining
     */
    unsigned remainingKeys() const;
    
private:
    /**
     * @brief The maze matrix
     */
    Matrix mapMatrix;

    /**
     * @brief The maze start location
     */
    Location beginLocation;

    /**
     * @brief The maze end location
     */
    Location endLocation;

    /**
     * @brief The walls locations
     */
    std::vector<Location> wallsLocations;

    /**
     * @brief The objects location
     */
    std::vector<Location> objectsLocations;

    /**
     * @brief The grass plots locations
     */
    std::vector<Location> grassLocations;

    /**
     * @brief The keys locations
     */
    std::vector<Location> keysLocations;
};

#endif // MAP_H
