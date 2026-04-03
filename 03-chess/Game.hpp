#pragma once

#include "Board.hpp"
#include "Player.hpp"
#include "MoveValidator.hpp"

class Game {
private:
    Board board;
    Player* p1;
    Player* p2;
    Player* curr;

public:
    Game(Player* p1, Player* p2);
    bool canMove(Position from, Position to);

};