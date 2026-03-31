#pragma once   
#include "Board.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include <queue>

class Game {
private:
    Board* board;
    Dice* dice;
    std::queue<Player*> players;

public:
    Game(Board* b, Dice* d);
    void addPlayer(Player* p);
    void play();
};