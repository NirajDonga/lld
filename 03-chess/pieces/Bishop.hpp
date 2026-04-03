#pragma once

#include "./Piece.hpp"

class Bishop : public Piece {
public:
    Bishop(bool isWhite) : Piece(isWhite) {}

    bool legalMove(const Position& from, const Position& to) const override ;
    int getPoints() const override {
        return 3;
    }
   
};




