#include "Player.hpp"

Player::Player(std::string name) {
    this->name = name;
    this->position = 0;
}

std::string Player::getName() {
    return name;
}

int Player::getPosition() {
    return position;
}

void Player::setPosition(int pos) {
    position = pos;
}