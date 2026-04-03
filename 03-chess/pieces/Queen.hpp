#pragma once

#include "./Piece.hpp"

class Queen : public Piece {
public:
    Queen(bool isWhite) : Piece(isWhite) {}

    bool legalMove(const Position&, const Position&) const override {
        return false;
    }

    int getPoints() const override {
        return 9;
    }

    
   
};




