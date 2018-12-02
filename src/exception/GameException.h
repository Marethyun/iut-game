#ifndef IUT_GAME_GAMEEXCEPTION_H
#define IUT_GAME_GAMEEXCEPTION_H


#include <exception>
#include <string>

class GameException : std::exception {

public:
    GameException(const std::string &message) noexcept;

    const char* what() const noexcept override;

protected:
    const std::string message;
};


#endif
