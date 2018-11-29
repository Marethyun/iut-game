#include "Color.h"

const std::string Color::bold(vt100("1"));

const std::string Color::reset(vt100("0"));
const std::string Color::black(vt100("30"));
const std::string Color::red(vt100("31"));
const std::string Color::green(vt100("32"));
const std::string Color::yellow(vt100("33"));
const std::string Color::blue(vt100("34"));
const std::string Color::magenta(vt100("35"));
const std::string Color::cyan(vt100("36"));
const std::string Color::lightGray(vt100("37"));

const std::string Color::bg_black(vt100("40"));
const std::string Color::bg_red(vt100("41"));
const std::string Color::bg_green(vt100("42"));
const std::string Color::bg_yellow(vt100("43"));
const std::string Color::bg_blue(vt100("44"));
const std::string Color::bg_magenta(vt100("45"));
const std::string Color::bg_cyan(vt100("46"));
const std::string Color::bg_lightgray(vt100("47"));

std::string Color::vt100(std::string code) {
    return "\033[" + code + 'm';
}
