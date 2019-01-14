#ifndef IUT_GAME_COLOR_H
#define IUT_GAME_COLOR_H

/**
 * @file Color.h
 * @brief Header for the Color class
 * @author Ange Bacci
 */

#include <string>

/**
 * @class Color
 * @brief The format class
 *
 * This class does not only include colors, but all v100 formatting codes.
 *
 * @see http://www.termsys.demon.co.uk/vtansi.htm#colors
 */
class Color {
public:
    /**
     * @brief The vt100 reset code
     *
     * Use this to reset formats to terminal's default
     *
     * @see Terminal
     */
    static const std::string reset;

    /**
     * @brief The vt100 bold code
     */
    static const std::string bold;

    /**
     * @brief The vt100 dim code
     */
    static const std::string dim;

    /**
     * @brief The vt100 underline/underscore code
     */
    static const std::string underscore;

    /**
     * @brief The vt100 blink code
     */
    static const std::string blink;

    /**
     * @brief The vt100 reverse code
     */
    static const std::string reverse;

    /**
     * @brief The vt100 code to hide text
     */
    static const std::string hidden;

    /**
     * @brief The vt100 code for the black color
     */
    static const std::string black;

    /**
     * @brief The vt100 code for the red color
     */
    static const std::string red;

    /**
     * @brief The vt100 code for the green color
     */
    static const std::string green;

    /**
     * @brief The vt100 code for the yellow color
     */
    static const std::string yellow;

    /**
     * @brief The vt100 code for the blue color
     */
    static const std::string blue;

    /**
     * @brief The vt100 code for the magenta color
     */
    static const std::string magenta;

    /**
     * @brief The vt100 code for the cyan color
     */
    static const std::string cyan;

    /**
     * @brief The vt100 code for the white color
     */
    static const std::string white;

    /**
     * @brief The vt100 code for the black background color
     */
    static const std::string bg_black;

    /**
     * @brief The vt100 code for the red background color
     */
    static const std::string bg_red;

    /**
     * @brief The vt100 code for the green background color
     */
    static const std::string bg_green;

    /**
     * @brief The vt100 code for the yellow background color
     */
    static const std::string bg_yellow;

    /**
     * @brief The vt100 code for the blue background color
     */
    static const std::string bg_blue;

    /**
     * @brief The vt100 code for the magenta background color
     */
    static const std::string bg_magenta;

    /**
     * @brief The vt100 code for the cyan background color
     */
    static const std::string bg_cyan;

    /**
     * @brief The vt100 code for the white background color
     */
    static const std::string bg_white;
private:

    /**
     * @brief Assemble the vt100 escape sequence with the provided code
     *
     * @param code The vt100 code
     * @return The escape sequence
     */
    static std::string vt100(std::string code);
};


#endif
