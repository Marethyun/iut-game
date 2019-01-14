#ifndef MAZE_H
#define MAZE_H
#include <vector>
#include <cstdlib>
#include <ctime>

/**
 * @file maze.h
 * @brief Provides functions for maze generation
 * @author Jules Clerc
 */

/**
 * @brief CVLine a type representing a line in the maze matrix
 */
typedef std::vector <char> CVLine;

/**
 * @brief CMatrix a type representing the maze matrix
 */
typedef std::vector <CVLine> CMatrix; 

/**
 * @brief CExtract a type representing a coordinate in the maze matrix
 */
typedef std::pair <unsigned, unsigned> CExtract;

/**
 * @brief Move up the extractor
 * @param Mat The extracting matrix
 * @param CExtract Represents the coordinates of the extractor that must be updated
 * @return updated extractor coordinates
 */
std::pair <unsigned, unsigned> GoTop (CMatrix & Mat, std::pair <unsigned, unsigned> CExtract);

/**
 * @brief GoTop Move right the extractor
 * @param Mat The extracting matrix
 * @param CExtract Represents the coordinates of the extractor that must be updated
 * @return updated extractor coordinates
 */
std::pair <unsigned, unsigned> GoRight (CMatrix & Mat, std::pair <unsigned, unsigned> CExtract);

/**
 * @brief GoBottom move bottom the extractor
 * @param Mat The extracting matrix
 * @param CExtract Represents the coordinates of the extractor that must be updated
 * @return updated extractor coordinates
 */
std::pair <unsigned, unsigned> GoBottom (CMatrix & Mat, std::pair <unsigned, unsigned> CExtract);

/**
 * @brief GoLeft Move left the extractor
 * @param Mat The extracting matrix
 * @param CExtract Represents the coordinates of the extractor that must be updated
 * @return updated extractor coordinates
 */
std::pair <unsigned, unsigned> GoLeft (CMatrix & Mat, std::pair <unsigned, unsigned> CExtract);

/**
 * @brief Generate a maze
 * @param Mat The maze matrix
 * @param NbColumn The column number (must be odd)
 * @param NbLine The lines (rows) number (must be odd)
 * @param PosF y-coordinate of the maze start location
 * @param PosS x-coordinate of the maze start location
 * @param NbObjets Count of objects to dispatch on the maze
 * @param NumberZoneGrass count of grass plots
 * @param GrassSize size of the grass plots
 * @param NumberKey count of the keys to be placed
 * @return The final, generated maze matrix
 */
CMatrix gen_maze(CMatrix &Mat, unsigned NbColumn, unsigned NbLine, unsigned PosF, unsigned PosS, unsigned NbObjets,
                 unsigned NumberZoneGrass, unsigned GrassSize, unsigned NumberKey);

#endif // MAZE_H
