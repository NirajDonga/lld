#include "Player.hpp"

Player::Player(const std::string& name, bool flag) : name(name), isWhite(flag) {}
    
std::string Player::getName() const {
    return name;
}

bool Player::isWhiteSide() const {
    return isWhite;
}