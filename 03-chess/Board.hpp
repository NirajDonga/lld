#pragma once
#include <iostream>
#include <vector>

#include "Piece.hpp"

class Board {
private:
    std::vector<std::vector<Piece*>> grid{8, std::vector<Piece*>(8, nullptr)};
    Board();

public:
    void initializeBoard();
    void move();

};