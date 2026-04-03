#pragma once

#include "./Piece.hpp"

class Pawn : public Piece {
public:
    Pawn(bool isWhite) : Piece(isWhite) {}

    bool legalMove(const Position&, const Position&) const override {
        return false;
    }

    int getPoints() const override {
        return 1;
    }
    
    
   
};




