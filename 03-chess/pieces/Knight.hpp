#pragma once

#include "./Piece.hpp"

class Knight : public Piece {
public:
    Knight(bool isWhite) : Piece(isWhite) {}

    bool legalMove(const Position&, const Position&) const override {
        return false;
    }

    int getPoints() const override {
        return 3;
    }
    
   
};




