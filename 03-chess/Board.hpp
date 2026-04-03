#pragma once
#include <iostream>
#include <vector>

#include "Piece.hpp"

class Board {
private:
    std::vector<std::vector<Piece*>> grid{8, std::vector<Piece*>(8, nullptr)};

public:
    Board() = default;
    void initializeBoard();
    void move();
    Piece& getPiece(const Position& position);
    bool hasPiece(const Position& position);

};