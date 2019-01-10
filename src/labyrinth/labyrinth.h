#ifndef LABYRINTH_H
#define LABYRINTH_H
#include <vector>
#include <cstdlib>
#include <ctime>

/**
 * @file labyrinth.h
 * @brief provides functions for labyrinth generation
 */

/**
 * @brief CVLine un type représentant une ligne de la grille
 */
typedef std::vector <char> CVLine;

/**
 * @brief CMatrix un type représentant la grille
 */
typedef std::vector <CVLine> CMatrix; 

/**
 * @brief CExtract un type représentant une coordonnée dans la grille
 */
typedef std::pair <unsigned, unsigned> CExtract;

/**
 * @brief GoTop permet à l'extracteur de se déplacer vers le haut
 * @param Mat est la matrice en cours d'extraction
 * @param CExtract représente les coordonnées de l'extracteur qui doivent être actualisées
 * @return on retourne les coordonnées de l'extracteur actualisés
 */
std::pair <unsigned, unsigned> GoTop (CMatrix & Mat, std::pair <unsigned, unsigned> CExtract);

/**
 * @brief GoRight permet à l'extracteur de se déplacer vers la droite
 * @param Mat est la matrice en cours d'extraction
 * @param CExtract CExtract représente les coordonnées de l'extracteur qui doivent être actualisées
 * @return on retourne les coordonnées de l'extracteur actualisés
 */
std::pair <unsigned, unsigned> GoRight (CMatrix & Mat, std::pair <unsigned, unsigned> CExtract);

/**
 * @brief GoBottom permet à l'extracteur de se déplacer vers le bas
 * @param Mat est la matrice en cours d'extraction
 * @param CExtract CExtract représente les coordonnées de l'extracteur qui doivent être actualisées
 * @return on retourne les coordonnées de l'extracteur actualisés
 */

std::pair <unsigned, unsigned> GoBottom (CMatrix & Mat, std::pair <unsigned, unsigned> CExtract);

/**
 * @brief GoLeft permet à l'extracteur de se déplacer vers la gauche
 * @param Mat est la matrice en cours d'extraction
 * @param CExtract CExtract représente les coordonnées de l'extracteur qui doivent être actualisées
 * @return on retourne les coordonnées de l'extracteur actualisés
 */
std::pair <unsigned, unsigned> GoLeft (CMatrix & Mat, std::pair <unsigned, unsigned> CExtract);

/**
 * @brief genere_labyrinth est une fonction qui permet la génération du labyrinthe et de ces objets
 * @param Mat est la matrice qui contiendra chaque case du labyrinthe
 * @param NbColumn paramètre permettant de déterminer le nombre de colonnes (doit être impair)
 * @param NbLine paramètre permettant de déterminer le nombre de lignes (doit être impair)
 * @param PosF détermine le spawn de départ, la position verticale (y)
 * @param PosS détermine le spawn de départ, la position horizontale (x)
 * @param NbObjets détermine les nombres d'objets spéciaux a placer dans le labyrinthe de façon aléatoire
 * @param NumberZoneGrass détermine le nombre de zone d'herbe à placer aléatoirement
 * @param GrassSize détermine la taille de chacune de ces zones d'herbes
 * @param NumberKey détermine le nombre de clés
 * @return La matrice finale
 */
CMatrix genere_labyrinth (CMatrix & Mat, unsigned NbColumn, unsigned NbLine, unsigned PosF, unsigned PosS, unsigned NbObjets, unsigned NumberZoneGrass, unsigned GrassSize, unsigned NumberKey);

#endif // LABYRINTH_H
