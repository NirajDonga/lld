#pragma once
#include <iostream>
#include <vector>

#include "Piece.hpp"
#include "ChessTypes.hpp"

class Board {
private:
    std::vector<std::vector<Piece*>> grid{8, std::vector<Piece*>(8, nullptr)};

public:
    Board() = default;
    ~Board();
    void initializeBoard();
    bool move(const Position& from, const Position& to);
    Piece* getPiece(const Position& position);
    const Piece* getPiece(const Position& position) const;
    bool hasPiece(const Position& position) const;
};