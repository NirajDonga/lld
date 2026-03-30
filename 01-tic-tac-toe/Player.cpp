#include "Player.hpp"

using namespace std;

Player::Player(string playerName, Symbol s) {
    name = playerName; 
    playerSymbol = s; 
} 

string Player::getname() {
    return name;
}

Symbol* Player::getSymbol() {
    return &playerSymbol;
}