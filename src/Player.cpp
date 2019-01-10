#include "Player.h"

Player::Player(const Location &location, const Cell &appearance, const unsigned &vision)
    : location(location), appearance(appearance), vision(vision) {}

Location Player::getLocation() {
    return this->location;
}

Cell Player::getAppearance() {
    return this->appearance;
}

unsigned Player::getVision() {
    return this->vision;
}

void Player::setLocation(const Location &location) {
    this->location = location;
}

void Player::setAppearance(const Cell &appearance) {
    this->appearance = appearance;
}

void Player::setVision(const unsigned &vision) {
    this->vision = vision;
}
