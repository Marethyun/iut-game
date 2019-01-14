#ifndef DIFFICULTY_H
#define DIFFICULTY_H

/**
 * @file Difficulty.h
 * @brief Header for the Difficulty class
 * @author Ange Bacci
 */

#include <string>

/**
 * @class Difficulty
 * @brief A plain old object, representing a maze difficulty
 */
class Difficulty
{
public:
    /**
     * @brief The full constructor
     *
     * @param name The difficulty name
     * @param height The maze height
     * @param width The maze width
     * @param objectsCount The count of objects to dispatch in the maze
     * @param goodObjectProb The probability for good objects
     * @param keysCount The count of keys
     * @param grassCount The count of grass plots
     * @param grassSize The size of the grass plots
     * @param defaultVision The player default vision
     */
    Difficulty(const std::string &name,
               const unsigned &height,
               const unsigned &width,
               const unsigned &objectsCount,
               const double &goodObjectProb,
               const unsigned &keysCount,
               const unsigned &grassCount,
               const unsigned &grassSize,
               const unsigned &defaultVision
    );

    /**
     * @brief The difficulty name
     */
    const std::string name;

    /**
     * @brief The maze height
     */
    const unsigned height;

    /**
     * @brief The maze width
     */
    const unsigned width;

    /**
     * @brief The count of objects to dispatch in the maze
     */
    const unsigned objectsCount;

    /**
     * @brief The probability for good objects
     */
    const double goodObjectProb;

    /**
     * @brief The count of keys
     */
    const unsigned keysCount;

    /**
     * @brief The count of grass plots
     */
    const unsigned grassCount;

    /**
     * @brief The size of the grass plots
     */
    const unsigned grassSize;

    /**
     * @brief The player default vision
     */
    const unsigned defaultVision;
};

#endif // DIFFICULTY_H
