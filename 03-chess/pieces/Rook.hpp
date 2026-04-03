#pragma once

#include "./Piece.hpp"

class Rook : public Piece {
public:
    Rook(bool isWhite) : Piece(isWhite) {}

    bool legalMove(const Position&, const Position&) const override {
        return false;
    }

    int getPoints() const override {
        return 5;
    }
    
   
};




