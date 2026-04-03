#pragma once

#include "./Piece.hpp"

class King : public Piece {
public:
    King(bool isWhite) : Piece(isWhite) {}
    bool legalMove(const Position&, const Position&) const override {
        return false;
    }

    int getPoints() const override {
        return 100;
    }
    
   
};




