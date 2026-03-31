#pragma once   
#include "Board.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include <queue>

class Game {
private:
    Board board;
    Dice dice;
    std::queue<Player*> players;
    int boardSize;

public:
    Game(int sz);
    void addPlayer(Player* p);
    void play();
};