#ifndef IUT_GAME_GAMEEXCEPTION_H
#define IUT_GAME_GAMEEXCEPTION_H

/**
 * @file GameException.h
 * @brief Header for the GameException class
 * @author Ange Bacci
 */

#include <exception>
#include <string>

/**
 * @class GameException
 * @brief Exception thrown in the Game class
 */
class GameException : std::exception {

public:
    /**
     * @brief Initialize the exception with its message
     * @param message The message
     */
    GameException(const std::string &message) noexcept;

    const char* what() const noexcept override;

protected:
    /**
     * @brief The exception message
     */
    const std::string message;
};


#endif
