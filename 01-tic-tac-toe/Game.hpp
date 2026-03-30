#pragma once

#include <vector>
#include "Stratergies/WinningStratergies.hpp"
#include "Board.hpp"
#include "Player.hpp"

class Game {
private:  
    Player* player1;
    Player* player2;
    Player* currPlayer;
    std::vector<WinningStratergies*> strategies;
public:
    Board board;

public:
    Game(int size, Player* p1, Player* p2);
    bool makeMove(int r, int c);
};
