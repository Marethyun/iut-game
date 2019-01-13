#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "maze.h"

using namespace std;

pair <unsigned, unsigned> GoTop (CMatrix & Mat, pair <unsigned, unsigned> CExtract)
{
    Mat[CExtract.first - 1][CExtract.second] = '0';
    Mat[CExtract.first - 2][CExtract.second] = '0';
    CExtract.first = CExtract.first - 2;
    return CExtract;
}

pair <unsigned, unsigned> GoRight (CMatrix & Mat, pair <unsigned, unsigned> CExtract)
{
    Mat[CExtract.first][CExtract.second + 1] = '0';
    Mat[CExtract.first][CExtract.second + 2] = '0';
    CExtract.second = CExtract.second + 2;
    return CExtract;
}

pair <unsigned, unsigned> GoBottom (CMatrix & Mat, pair <unsigned, unsigned> CExtract)
{
    Mat[CExtract.first + 1][CExtract.second] = '0';
    Mat[CExtract.first + 2][CExtract.second] = '0';
    CExtract.first = CExtract.first + 2;
    return CExtract;
}

pair <unsigned, unsigned> GoLeft (CMatrix & Mat, pair <unsigned, unsigned> CExtract)
{
    Mat[CExtract.first][CExtract.second - 1] = '0';
    Mat[CExtract.first][CExtract.second - 2] = '0';
    CExtract.second = CExtract.second - 2;
    return CExtract;
}

CMatrix gen_maze(CMatrix &Mat, unsigned NbColumn, unsigned NbLine, unsigned PosF, unsigned PosS, unsigned NbObjets,
                 unsigned NumberZoneGrass, unsigned GrassSize, unsigned NumberKey)
{
    //basé sur une vidéo : https://www.youtube.com/watch?v=LLY9K0_y494&t=293s (à partir de 2:30 jusqu'a 3:30)
    //on genere la matrice
    srand(time(NULL));
    Mat.resize(NbLine);
    for (unsigned i(0); i < Mat.size(); i++)
    {
        Mat[i].resize(NbColumn);
    }
    //on remplit la matrice représenté par un #
    for (unsigned y(0); y < Mat.size(); y++)
    {
        for (unsigned x(0); x < Mat[y].size(); x++)
        {
            Mat[y][x] = '#';
        }
    }

    //création de l'extracteur + position dans le labyrinthe
    pair <unsigned, unsigned> CExtract; //proposer au joueur les dimensions
    CExtract.first = PosF;
    CExtract.second = PosS;
    Mat [CExtract.first][CExtract.second] = '0';

    //on crée un tableau qui va enregistrer les coordonnées des intersections
    vector < unsigned> TabCpt1;
    TabCpt1.resize(0);
    vector <unsigned> TabCpt2;
    TabCpt2.resize(0);

    //extraction cases du labyrinthe représenté par un 0
    for(;;)
    {
        int alea;
        alea = rand();
        //les différents "if" permettent de savoir les cases que l'on peut extraire
        //il y a plusieurs possibilités : soit l'extracteur est proche d'un mur soit il en est éloigné

        //dans ce cas l'extracteur est proche d'un coin
        if (CExtract.first == 0 && CExtract.second == 0) // coin en haut à gauche
        {
            if (Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : bas et droite
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoRight(Mat, CExtract);
                }
                else if (alea % 2 == 1)
                {
                    CExtract = GoBottom(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] != '#') //possiblilité de creusage : droite
            {
                CExtract = GoRight(Mat, CExtract);
            }
            else if (Mat[CExtract.first][CExtract.second + 2] != '#' && Mat[CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : bas
            {
                CExtract = GoBottom(Mat, CExtract);
            }
            else //possiblilité de creusage : aucune possibilité
            {
                CExtract.first = TabCpt1[TabCpt1.size() - 1];
                TabCpt1.resize(TabCpt1.size() - 1);
                CExtract.second = TabCpt2[TabCpt2.size() - 1];
                TabCpt2.resize(TabCpt2.size() - 1);
            }
        }
        else if (CExtract.first == 0 && CExtract.second == NbColumn - 1) // coin en haut à droite
        {
            if (Mat[CExtract.first][CExtract.second - 2] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : bas et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoLeft(Mat, CExtract);
                }
                else
                {
                    CExtract = GoBottom(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first][CExtract.second - 2] == '#' && Mat[CExtract.first + 2][CExtract.second] != '#') //possiblilité de creusage : gauche
            {
                CExtract = GoLeft(Mat, CExtract);
            }
            else if (Mat[CExtract.first][CExtract.second - 2] != '#' && Mat[CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : bas
            {
                CExtract = GoBottom(Mat, CExtract);
            }
            else //possiblilité de creusage : aucune possibilité
            {
                CExtract.first = TabCpt1[TabCpt1.size() - 1];
                TabCpt1.resize(TabCpt1.size() - 1);
                CExtract.second = TabCpt2[TabCpt2.size() - 1];
                TabCpt2.resize(TabCpt2.size() - 1);
            }
        }
        else if (CExtract.first == NbLine - 1 && CExtract.second == 0) // coin en bas à gauche
        {
            if (Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first - 2][CExtract.second] == '#') //possiblilité de creusage : haut et droite
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoRight(Mat, CExtract);
                }
                else
                {
                    CExtract = GoTop(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first - 2][CExtract.second] != '#') //possiblilité de creusage : droite
            {
                CExtract = GoRight(Mat, CExtract);
            }
            else if (Mat[CExtract.first][CExtract.second + 2] != '#' && Mat[CExtract.first - 2][CExtract.second] == '#') //possiblilité de creusage : haut
            {
                CExtract = GoTop(Mat, CExtract);
            }
            else //possiblilité de creusage : aucune possibilité
            {
                CExtract.first = TabCpt1[TabCpt1.size() - 1];
                TabCpt1.resize(TabCpt1.size() - 1);
                CExtract.second = TabCpt2[TabCpt2.size() - 1];
                TabCpt2.resize(TabCpt2.size() - 1);
            }
        }
        else if (CExtract.first == NbLine - 1 && CExtract.second == NbColumn - 1) // coin en bas à droite
        {
            if (Mat[CExtract.first][CExtract.second - 2] == '#' && Mat[CExtract.first - 2][CExtract.second] == '#') //possiblilité de creusage : haut et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoTop(Mat, CExtract);
                }
                else
                {
                    CExtract = GoLeft(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first][CExtract.second - 2] == '#' && Mat[CExtract.first - 2][CExtract.second] != '#') //possiblilité de creusage : gauche
            {
                CExtract = GoLeft(Mat, CExtract);
            }
            else if (Mat[CExtract.first][CExtract.second - 2] != '#' && Mat[CExtract.first - 2][CExtract.second] == '#') //possiblilité de creusage : haut
            {
                CExtract = GoTop(Mat, CExtract);
            }
            else //possiblilité de creusage : aucune possibilité
            {
                CExtract.first = TabCpt1[TabCpt1.size() - 1];
                TabCpt1.resize(TabCpt1.size() - 1);
                CExtract.second = TabCpt2[TabCpt2.size() - 1];
                TabCpt2.resize(TabCpt2.size() - 1);
            }
        }

        //dans ce cas l'extracteur est collé à un mur mais pas un coin
        else if (CExtract.first == 0) //collé au mur du haut
        {
            if (Mat[CExtract.first][CExtract.second + 2] == '#' && Mat [CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : droite, bas et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 3 == 0)
                {
                    CExtract = GoRight(Mat, CExtract);
                }
                if (alea % 3 == 1)
                {
                    CExtract = GoLeft(Mat, CExtract);
                }
                else
                {
                    CExtract = GoBottom(Mat, CExtract);
                }

            }
            else if (Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : droite et bas
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoBottom(Mat, CExtract);
                }
                else
                {
                    CExtract = GoRight(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : droite et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoRight(Mat, CExtract);
                }
                else
                {
                    CExtract = GoLeft(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : bas et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoLeft(Mat, CExtract);
                }
                else
                {
                    CExtract = GoBottom(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first][CExtract.second + 2] == '#') //droite
            {
                CExtract = GoRight(Mat, CExtract);
            }
            else if (Mat[CExtract.first + 2][CExtract.second] == '#') //bas
            {
                CExtract = GoBottom(Mat, CExtract);
            }
            else if (Mat[CExtract.first][CExtract.second - 2] == '#') //gauche
            {
                CExtract = GoLeft(Mat, CExtract);
            }
            else //aucune possibilité
            {
                CExtract.first = TabCpt1[TabCpt1.size() - 1];
                TabCpt1.resize(TabCpt1.size() - 1);
                CExtract.second = TabCpt2[TabCpt2.size() - 1];
                TabCpt2.resize(TabCpt2.size() - 1);
            }
        }
        else if (CExtract.second == NbColumn - 1) //collé au mur de droite
        {
            if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : haut, bas et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 3 == 0)
                {
                    CExtract = GoTop(Mat, CExtract);
                }
                if (alea % 3 == 1)
                {
                    CExtract = GoBottom(Mat, CExtract);
                }
                else
                {
                    CExtract = GoLeft(Mat, CExtract);
                }

            }
            else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : haut et bas
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoTop(Mat, CExtract);
                }
                else
                {
                    CExtract = GoBottom(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : haut et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoTop(Mat, CExtract);
                }
                else
                {
                    CExtract = GoLeft(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : bas et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoLeft(Mat, CExtract);
                }
                else
                {
                    CExtract = GoBottom(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first - 2][CExtract.second] == '#') //possiblilité de creusage : haut
            {
                CExtract = GoTop(Mat, CExtract);
            }
            else if (Mat[CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : bas
            {
                CExtract = GoBottom(Mat, CExtract);
            }
            else if (Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : gauche
            {
                CExtract = GoLeft(Mat, CExtract);
            }
            else //possiblilité de creusage : aucune possibilité
            {
                CExtract.first = TabCpt1[TabCpt1.size() - 1];
                TabCpt1.resize(TabCpt1.size() - 1);
                CExtract.second = TabCpt2[TabCpt2.size() - 1];
                TabCpt2.resize(TabCpt2.size() - 1);
            }
        }
        else if (CExtract.first == NbLine - 1) //collé au mur du bas
        {
            if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : haut, droite et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 3 == 0)
                {
                    CExtract = GoRight(Mat, CExtract);
                }
                if (alea % 3 == 1)
                {
                    CExtract = GoTop(Mat, CExtract);
                }
                else
                {
                    CExtract = GoLeft(Mat, CExtract);
                }

            }
            else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] == '#') //possiblilité de creusage : haut et droite
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoTop(Mat, CExtract);
                }
                else
                {
                    CExtract = GoRight(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : haut et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoTop(Mat, CExtract);
                }
                else
                {
                    CExtract = GoLeft(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : droite et gauche
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoRight(Mat, CExtract);
                }
                else
                {
                    CExtract = GoLeft(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first - 2][CExtract.second] == '#') //possiblilité de creusage : haut
            {
                CExtract = GoTop(Mat, CExtract);
            }
            else if (Mat[CExtract.first][CExtract.second + 2] == '#') //possiblilité de creusage : droite
            {
                CExtract = GoRight(Mat, CExtract);
            }
            else if (Mat[CExtract.first][CExtract.second - 2] == '#') //possiblilité de creusage : gauche
            {
                CExtract = GoLeft(Mat, CExtract);
            }
            else //possiblilité de creusage : aucune possibilité
            {
                CExtract.first = TabCpt1[TabCpt1.size() - 1];
                TabCpt1.resize(TabCpt1.size() - 1);
                CExtract.second = TabCpt2[TabCpt2.size() - 1];
                TabCpt2.resize(TabCpt2.size() - 1);
            }
        }
        else if (CExtract.second == 0) //collé au mur de gauche
        {
            if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : haut, droite et bas
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 3 == 0)
                {
                    CExtract = GoTop(Mat, CExtract);
                }
                if (alea % 3 == 1)
                {
                    CExtract = GoRight(Mat, CExtract);
                }
                else
                {
                    CExtract = GoBottom(Mat, CExtract);
                }

            }
            else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat [CExtract.first][CExtract.second + 2] == '#') //possiblilité de creusage : haut et droite
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoRight(Mat, CExtract);
                }
                else
                {
                    CExtract = GoTop(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat [CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : haut et bas
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoTop(Mat, CExtract);
                }
                else
                {
                    CExtract = GoBottom(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : droite et bas
            {
                TabCpt1.resize(TabCpt1.size() + 1);
                TabCpt1[TabCpt1.size() - 1] = CExtract.first;
                TabCpt2.resize(TabCpt2.size() + 1);
                TabCpt2[TabCpt2.size() - 1] = CExtract.second;
                if (alea % 2 == 0)
                {
                    CExtract = GoBottom(Mat, CExtract);
                }
                else
                {
                    CExtract = GoRight(Mat, CExtract);
                }
            }
            else if (Mat[CExtract.first - 2][CExtract.second] == '#') //possiblilité de creusage : haut
            {
                CExtract = GoTop(Mat, CExtract);
            }
            else if (Mat[CExtract.first][CExtract.second + 2] == '#') //possiblilité de creusage : droite
            {
                CExtract = GoRight(Mat, CExtract);
            }
            else if (Mat[CExtract.first + 2][CExtract.second] == '#') //possiblilité de creusage : bas
            {
                CExtract = GoBottom(Mat, CExtract);
            }
            else //possiblilité de creusage : aucune possibilité
            {
                CExtract.first = TabCpt1[TabCpt1.size() - 1];
                TabCpt1.resize(TabCpt1.size() - 1);
                CExtract.second = TabCpt2[TabCpt2.size() - 1];
                TabCpt2.resize(TabCpt2.size() - 1);
            }
        }

        //dans ce cas l'extracteur n'est pas collé à un mur (et un coin)
        else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //toutes les directions possibles
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 4 == 0)
            {
                CExtract = GoBottom(Mat, CExtract);
            }
            else if (alea % 4 == 1)
            {
                CExtract = GoRight(Mat, CExtract);
            }
            else if (alea % 4 == 2)
            {
                CExtract = GoLeft(Mat, CExtract);
            }
            else
            {
                CExtract = GoTop(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] != '#') //haut, bas et droite
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 3 == 0)
            {
                CExtract = GoTop(Mat, CExtract);
            }
            else if (alea % 3 == 1)
            {
                CExtract = GoBottom(Mat, CExtract);
            }
            else
            {
                CExtract = GoRight(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //haut, gauche et droite
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 3 == 0)
            {
                CExtract = GoTop(Mat, CExtract);
            }
            else if (alea % 3 == 1)
            {
                CExtract = GoLeft(Mat, CExtract);
            }
            else
            {
                CExtract = GoRight(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] != '#' && Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //haut, bas et gauche
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 3 == 0)
            {
                CExtract = GoTop(Mat, CExtract);
            }
            else if (alea % 3 == 1)
            {
                CExtract = GoBottom(Mat, CExtract);
            }
            else
            {
                CExtract = GoLeft(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //bas, gauche et droite
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 3 == 0)
            {
                CExtract = GoBottom(Mat, CExtract);
            }
            else if (alea % 3 == 1)
            {
                CExtract = GoLeft(Mat, CExtract);
            }
            else
            {
                CExtract = GoRight(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second - 2] != '#') //haut et droite
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 2 == 0)
            {
                CExtract = GoRight(Mat, CExtract);
            }
            else
            {
                CExtract = GoTop(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] != '#' && Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] != '#') //haut et bas
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 2 == 0)
            {
                CExtract = GoTop(Mat, CExtract);
            }
            else
            {
                CExtract = GoBottom(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] != '#' && Mat[CExtract.first + 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //haut et gauche
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 2 == 0)
            {
                CExtract = GoTop(Mat, CExtract);
            }
            else
            {
                CExtract = GoLeft(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] != '#') //droite et bas
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 2 == 0)
            {
                CExtract = GoRight(Mat, CExtract);
            }
            else
            {
                CExtract = GoBottom(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //gauche et droite
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 2 == 0)
            {
                CExtract = GoLeft(Mat, CExtract);
            }
            else
            {
                CExtract = GoRight(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second + 2] != '#' && Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //bas et gauche
        {
            TabCpt1.resize(TabCpt1.size() + 1);
            TabCpt1[TabCpt1.size() - 1] = CExtract.first;
            TabCpt2.resize(TabCpt2.size() + 1);
            TabCpt2[TabCpt2.size() - 1] = CExtract.second;
            if (alea % 2 == 0)
            {
                CExtract = GoLeft(Mat, CExtract);
            }
            else
            {
                CExtract = GoBottom(Mat, CExtract);
            }
        }
        else if (Mat[CExtract.first - 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second + 2] != '#' && Mat[CExtract.first + 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second - 2] != '#') //haut
        {
            CExtract = GoTop(Mat, CExtract);
        }
        else if (Mat[CExtract.first - 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second + 2] == '#' && Mat[CExtract.first + 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second - 2] != '#') //droite
        {
            CExtract = GoRight(Mat, CExtract);
        }
        else if (Mat[CExtract.first - 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second + 2] != '#' && Mat[CExtract.first + 2][CExtract.second] == '#' && Mat[CExtract.first][CExtract.second - 2] != '#') //bas
        {
            CExtract = GoBottom(Mat, CExtract);
        }
        else if (Mat[CExtract.first - 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second + 2] != '#' && Mat[CExtract.first + 2][CExtract.second] != '#' && Mat[CExtract.first][CExtract.second - 2] == '#') //gauche
        {
            CExtract = GoLeft(Mat, CExtract);
        }
        else //aucune possibilités
        {
            CExtract.first = TabCpt1[TabCpt1.size() - 1];
            TabCpt1.resize(TabCpt1.size() - 1);
            CExtract.second = TabCpt2[TabCpt2.size() - 1];
            TabCpt2.resize(TabCpt2.size() - 1);
        }
        if (TabCpt1.size() == 0) //condition de sortie
        {
            break;
        }
    }
    //nombre de zones d'herbes
    for (unsigned i = 0; i < NumberZoneGrass; i++)
    {
        //ajouter les zones d'herbes représenté par un x
        pair <unsigned, unsigned> PosGrass;
        for(;;)
        {
            PosGrass.first = rand() % NbLine;
            PosGrass.second = rand() % NbColumn;
            if (PosGrass.first + GrassSize < NbLine - 1 && PosGrass.second + GrassSize < NbColumn - 1)
            {
                break;
            }
        }
        for (unsigned yG = PosGrass.first; yG < (PosGrass.first + GrassSize); yG++)
        {
            for (unsigned xG = PosGrass.second; xG < (PosGrass.second + GrassSize); xG++)
            {
                if (Mat[yG][xG] == '0')
                {
                    Mat[yG][xG] = 'x';
                }
            }
        }
    }
    //ajouter les cases bonus représenté par un 1
    for (unsigned i = 0; i < NbObjets; i++)
    {
        unsigned alea1 = rand() % NbLine;
        unsigned alea2 = rand() % NbColumn;
        while (Mat[alea1][alea2] != '0')
        {
            alea1 = rand() % NbLine;
            alea2 = rand() % NbColumn;
        }
        Mat[alea1][alea2] = '1';
    }
    //ajouter des clefs représenté par un k
    for (unsigned i = 0; i < NumberKey; i++)
    {
        unsigned aleaK1 = rand() % NbLine;
        unsigned aleaK2 = rand() % NbColumn;
        while (Mat[aleaK1][aleaK2] == '#')
        {
            aleaK1 = rand() % NbLine;
            aleaK2 = rand() % NbColumn;
        }
        Mat[aleaK1][aleaK2] = 'k';
    }

    //ajouter le téléporteur en bas à droite
    if (Mat[NbLine - 1][NbColumn - 1] != '#')
    {
        Mat[NbLine - 1][NbColumn - 1] = 'f';
    }
    else if (Mat[NbLine - 2][NbColumn - 1] != '#')
    {
        Mat[NbLine - 2][NbColumn - 1] = 'f';
    }
    else if (Mat[NbLine - 1][NbColumn - 2] != '#')
    {
        Mat[NbLine - 1][NbColumn - 2] = 'f';
    }
    //ajouter case départ
    Mat[PosF][PosS] = 'd';
    //derniere etape : retourner le calque du labyrinthe fini
    return Mat;
}
