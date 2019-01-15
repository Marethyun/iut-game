#ifndef IUT_GAME_TERMINAL_H
#define IUT_GAME_TERMINAL_H

/**
 * @file Terminal.h
 * @brief Header for the Terminal class
 * @author Ange Bacci
 */

#include <string>
#include "Matrix.h"
#include "Cell.h"

/**
 * @class Terminal
 * @brief Provides terminal utilities
 *
 * This class regroups vt100 and matrix/cell display utilities
 */
class Terminal {
public:
    /**
     * @brief Clears the terminal
     */
    static void clear();

    /**
     * @brief Sets the print format
     *
     * @see Color
     *
     * @param string The format
     */
    static void color(std::string string);

    /**
     * @brief Prints a matrix to the terminal
     * @param cellMatrix The matrix
     * 
     * Known issue: The calls to vt100 features to save, un-save, and restore the cursor position
     * are unsupported on common OSX consoles.
     */
    static void matrix(Matrix &cellMatrix);

    /**
     * @brief Prints a cell to the terminal
     * @param cel The cell
     */
    static void cell(const Cell &cel);

    /**
     * @brief Move the cursor somewhere
     *
     * @param x The cursor x-coordinate
     * @param y The cursor y-coordinate
     */
    static void moveCursor(const unsigned &x, const unsigned &y);

    /**
     * @brief vt100: Saves the cursor position
     */
    static void saveCursor();

    /**
     * @brief vt100: Un-save the cursor position
     */
    static void unsaveCursor();

    /**
     * @brief vt100: Restores the cursor position to the saved one
     */
    static void restoreCursor();

    /**
     * @brief Moves the cursor n times up
     * @param count Times count
     */
    static void cursorUp(const unsigned &count);

    /**
     * @brief Moves the cursor n times down
     * @param count Times count
     */
    static void cursorDown(const unsigned &count);

    /**
     * @brief Moves the cursor n times back (left)
     * @param count Times count
     */
    static void cursorBack(const unsigned &count);

    /**
     * @brief Moves the cursor n times forward (right)
     * @param count Times count
     */
    static void cursorForward(const unsigned &count);

    /**
     * @brief Gets the next inputted character, without waiting for 'ENTER'
     *
     * Uses the termios.h utility to capture a character asynchronously.
     *
     * @return The next inputted character
     */
    static char getch();
};


#endif
