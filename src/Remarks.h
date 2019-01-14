#ifndef REMARKS_H
#define REMARKS_H

/**
 * @file Remarks.h
 * @brief Header for the Remarks class
 * @author Ange Bacci
 */

#include <string>

/**
 * @class Remarks
 * @brief A class that provides static utilities to get remarks
 *
 * This class is used to get the 'Le Saviez-vous? remarks in the difficulty menu.
 * The file containing the remarks may be named 'REMARKS'.
 *
 * @see DifficultyScene
 */
class Remarks
{
public:
    /**
     * @brief Gets a random remark from the remarks file
     * @return a random remark, an empty string if the file is empty, an error if the file could not be read
     */
    static std::string getRandom();
private:
    Remarks();
    
};

#endif // REMARKS_H
