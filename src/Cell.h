#ifndef IUT_GAME_CELL_H
#define IUT_GAME_CELL_H

/**
 * @file Cell.h
 * @brief Header for the Cell class
 * @author Ange Bacci
 */

#include <string>
#include "Location.h"

/**
 * @class Cell
 * @brief A plain old object, representing a terminal cell
 *
 * A cell contains a formatted character.
 *
 * e.g.: A blue, underlined 'Y' on red background
 *
 * @see Color
 * @see Terminal
 */
class Cell {

public:
    /**
     * @brief The character considered as null.
     *
     * Used to build default cells, this character may be replaced by merging two cells.
     *
     * @see #operator+(const Cell & other)
     */
    static const char NULCHAR = ' ';

    /**
     * @brief The default constructor
     */
    Cell();

    /**
     * @brief The format constructor, builds a cell from a format
     *
     * @see Color
     *
     * @param format The format
     */
    Cell(const std::string &format);

    /**
     * @brief The character constructor, builds a cell from a character
     *
     * @param character The character
     */
    Cell(const char character);

    /**
     * @brief The full constructor, takes a format and a character to build the cell
     *
     * @see Color
     *
     * @param format The format
     * @param character The character
     */
    Cell(const std::string &format, const char character);

    /**
     * @brief Getter for the format
     * @return The cell @ref #format
     */
    const std::string &getFormat() const;

    /**
     * @brief Getter for the character
     * @return The cell @ref #character
     */
    const char &getCharacter() const;

    /**
     * @brief Setter for the format
     * @param format The format
     */
    void setFormat(const std::string &format);

    /**
     * @brief Setter for the character
     * @param character The character
     */
    void setCharacter(const char &character);

    /**
     * @brief The merging operator
     *
     * The merging rules are the following:
     *
     * The format is merged anyway, by adding the other format to the current cell one.
     * The character is replaced by the other cell one only if it contains not the @ref #NULCHAR.
     *
     * e.g.:
     * Cell 1: A 'Y' red
     * Cell 2: A NULCHAR on blue background
     *
     * Cell 1 + Cell 2 = A 'Y' red on blue background
     *
     * @param other The other cell
     * @return The merged cell
     */
    Cell operator+(const Cell & other);

private:
    /**
     * @brief The cell format
     *
     * Mostly a combination of colors
     *
     * @see Color
     */
    std::string format;

    /**
     * @brief The cell character
     */
    char character;

};


#endif
