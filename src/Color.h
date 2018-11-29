#ifndef IUT_GAME_COLOR_H
#define IUT_GAME_COLOR_H

#include <string>

class Color {
public:
    static const std::string bold;

    static const std::string reset;
    static const std::string black;
    static const std::string red;
    static const std::string green;
    static const std::string yellow;
    static const std::string blue;
    static const std::string magenta;
    static const std::string cyan;
    static const std::string lightGray;

    static const std::string bg_black;
    static const std::string bg_red;
    static const std::string bg_green;
    static const std::string bg_yellow;
    static const std::string bg_blue;
    static const std::string bg_magenta;
    static const std::string bg_cyan;
    static const std::string bg_lightgray;
private:
    static std::string vt100(std::string code);
};


#endif
