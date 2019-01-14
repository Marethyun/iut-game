#ifndef IUT_GAME_MATRIX_H
#define IUT_GAME_MATRIX_H

/**
 * @file Matrix.h
 * @brief Header for the Matrix class
 * @author Ange Bacci
 */

#include <vector>
#include <string>
#include "Location.h"
#include "Cell.h"

/**
 * @class Matrix
 * @brief Represents a Cell matrix in the terminal
 *
 * Contains a vector of vectors of cell, or a bi-dimensional array stored in column-major order.
 *
 * @see Terminal
 */
class Matrix {
public:
    /**
     * @brief The default constructor
     *
     * Builds a null matrix of default cells
     */
    Matrix();

    /**
     * @brief The full constructor
     *
     * Builds a matrix with its height, width, and default cell
     *
     * @param height The matrix height
     * @param width The matrix width
     * @param defaultElem The default cell
     */
    Matrix(const unsigned int &height, const unsigned int &width, const Cell &defaultElem);

    /**
     * @brief The vector constructor
     *
     * Builds a matrix with its vector of vectors of cells
     *
     * @param matrix The vector
     */
    Matrix(const std::vector<std::vector<Cell>> &matrix);

    /**
     * @brief Getter for the matrix height
     *
     * @return The @ref #height
     */
    unsigned int getHeight() const;

    /**
     * @brief Getter for the matrix width
     *
     * @return The @ref #width
     */
    unsigned int getWidth() const;

    /**
     * @brief Gets the cell at the provided coordinates
     *
     * @param x The x-coordinate
     * @param y The y-coordinate
     * @return The corresponding Cell
     */
    Cell & get(const unsigned &x, const unsigned &y);

    /**
     * @brief Same as get(const unsigned &x, const unsigned &y), with a Location
     *
     * @param location The Cell Location
     * @return The corresponding Cell
     */
    Cell & get(const Location &location);

    /**
     * @brief Returns the pointer to the corresponding cell
     * @param x The x-coordinates
     * @param y The y-coordinates
     * @return A pointer to the corresponding Cell
     */
    Cell * at(const unsigned &x, const unsigned &y);

    /**
     * @brief Same as at(const unsigned &x, const unsigned &y), with a Location
     * @param location The Cell Location
     * @return A pointer to the corresponding Cell
     */
    Cell * at(const Location &location);

    /**
     * @brief Replaces a Cell by the provided one, at the coordinates
     *
     * Just assigns the provided cell at the provided coordinates, overriding the previous
     *
     * @param x The x-coordinate
     * @param y The y-coordinate
     * @param other The replacing Cell
     */
    void replace(const unsigned &x, const unsigned &y, const Cell &other);

    /**
     * @brief Same as replace(const unsigned &x, const unsigned &y, const Cell &other), with a Location
     *
     * @param location The Cell Location
     * @param other The replacing Cell
     */
    void replace(const Location &location, const Cell &other);

    /**
     * @brief Replaces a Matrix from the provided coordinates
     *
     * Replaces cells by an entire Matrix, from the provided coordinates as its top-left corner (0, 0)
     * This method is not bounds-safe, it will stop with a segmentation fault if the replacing matrix is too big
     *
     * @param x The top-left corner x-coordinate
     * @param y The top-left corner y-coordinate
     * @param other The replacing Matrix
     */
    void replace(const unsigned &x, const unsigned &y, Matrix &other);

    /**
     * @brief Same as replace(const unsigned &x, const unsigned &y, Matrix &other), with a Location
     *
     * @param location The top-left corner Location
     * @param other The replacing Matrix
     */
    void replace(const Location &location, Matrix &other);

    /**
     * @brief Merges a Cell with a provided one at the coordinates
     *
     * Uses the merging of two Cell objects
     * @see Cell
     *
     * @param x The x-coordinate
     * @param y The y-coordinate
     * @param other The Cell to merge with
     */
    void merge(const unsigned &x, const unsigned &y, const Cell &other);

    /**
     * @brief Same as merge(const unsigned &x, const unsigned &y, const Cell &other), with a Location
     * @param location The Cell Location
     * @param other The Cell to merge with
     */
    void merge(const Location &location, const Cell &other);

    /**
     * @brief Merges a Matrix from the provided coordinates
     *
     * Merge cells of an entire Matrix, from the provided coordinates as its top-left corner (0, 0)
     * This method is not bounds-safe, it will stop with a segmentation fault if the merging matrix is too big
     *
     * Uses the merging of two Cell objects
     * @see Cell
     *
     * @param x The top-left corner x-coordinate
     * @param y The top-left corner y-coordinate
     * @param other The Matrix to merge with
     */
    void merge(const unsigned &x, const unsigned &y, Matrix &other);

    /**
     * @brief Same as merge(const unsigned &x, const unsigned &y, Matrix &other), with a Location
     *
     * @param location The top-left corner Location
     * @param other The matrix to merge with
     */
    void merge(const Location &location, Matrix &other);

    /**
     * @brief Merges a text Matrix built with the provided text, at the provided coordinates
     *
     * Wraps the text in the provided width, put it in a Matrix and merge it from the provided coordinates.
     * Adds the provided format to the text Cell Matrix.
     *
     * Breaks the text calling the wrap(std::string text, unsigned width) method
     *
     * @param x The x-coordinate
     * @param y The y-coordinate
     * @param width The width to wrap the text with
     * @param format The text format
     * @param text The text to merge
     */
    void text(const unsigned &x, const unsigned &y, const unsigned &width, const std::string &format, const std::string &text);

    /**
     * @brief Same as text(const unsigned &x, const unsigned &y, const unsigned &width, const std::string &format, const std::string &text), with a Location
     *
     * @param location The Location
     * @param width The width to wrap the text with
     * @param format The text format
     * @param text The text to merge
     */
    void text(const Location &location, const unsigned &width, const std::string &format, const std::string &text);

    /**
     * @brief Same as text(const unsigned &x, const unsigned &y, const unsigned &width, const std::string &format, const std::string &text), without a width
     *
     * Wraps the text following this Matrix width
     *
     * @param x The x-coordinate
     * @param y The y-coordinate
     * @param format The text format
     * @param text The text to merge
     */
    void text(const unsigned &x, const unsigned &y, const std::string &format, const std::string &text);

    /**
     * @brief Same as text(const unsigned &x, const unsigned &y, const std::string &format, const std::string &text), witha Location
     *
     * @param location The Location
     * @param format The text format
     * @param text The text to merge
     */
    void text(const Location &location, const std::string &format, const std::string &text);

    /**
     * @brief Crops a part of the matrix, from top-left corner coordinates, to bottom-right coordinates
     *
     * This method is bounds safe, and fill the out-of-bounds coordinates with a default Cell
     * Fails (with a C assertion) if the coordinates are incoherent.
     *
     * @param x The top-left corner x-coordinate
     * @param y The top-left corner y-coordinate
     * @param x2 The bottom-right corner x-coordinate
     * @param y2 The bottom-right corner y-coordinate
     * @param defaultCell The cell to use if bounds are reached
     * @return The cropped Matrix
     */
    Matrix crop(const int &x, const int &y, const int &x2, const int &y2, const Cell &defaultCell);

    /**
     * @brief Same as crop(const int &x, const int &y, const int &x2, const int &y2, const Cell &defaultCell), with two Location
     * @param loc1 The top-left corner Location
     * @param loc2 The bottom-right corner Location
     * @param defaultCell The cell to use if bounds are reached
     * @return The cropped Matrix
     */
    Matrix crop(const Location &loc1, const Location &loc2, const Cell &defaultCell);

    /**
     * @brief Calculates the center Location of the matrix
     *
     * @return The center Location
     */
    Location center();

    /**
     * @brief Check whether the coordinates are in the matrix bounds
     *
     * @param x The x-coordinate
     * @param y The y-coordinate
     * @return true if the coordinates are in the matrix bounds
     */
    bool isInBounds(const int &x, const int &y);

    /**
     * @brief Same as isInBounds(const int &x, const int &y), with a Location
     * @param location The Location
     * @return true if the Location is in the matrix bounds
     */
    bool isInBounds(const Location &location);

private:
    /**
     * @brief The matrix height
     */
    unsigned height;

    /**
     * @brief The matrix width
     */
    unsigned width;

    /**
     * @brief The raw matrix vector
     */
    std::vector<std::vector<Cell>> matrix;

    /**
     * @brief Wrap text following the provided width
     *
     * Breaks words if possible, adds line-feed characters (LF, 0x0A) at the end of wrapped lines
     *
     * @param text The text to wrap
     * @param width The width
     * @return The wrapped text
     */
    std::string wrap (std::string text, unsigned width);
};

#endif
