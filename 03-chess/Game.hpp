#pragma once

#include "Board.hpp"
#include "Player.hpp"
#include "MoveValidator.hpp"

class Game {
private:
    Board board;
    Player* p1;
    Player* p2;
    Player* currTurn;
    MoveValidator mv;

public:
    Game(Player* p1, Player* p2);
    bool canMove(const Position& from, const Position& to);

};