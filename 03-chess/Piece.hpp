#pragma once

#include "../ChessTypes.hpp"

class Piece {
private:
    bool white;
    bool hasMoved;
    bool killed;

public: 
    Piece(bool isWhitePiece)
        : white(isWhitePiece), hasMoved(false), killed(false) {}

    virtual ~Piece() = default;
    virtual int getPoints() const = 0;
    virtual bool legalMove(const Position& from, const Position& to) const = 0;

    bool isWhite() const {
        return white;
    }

    bool hasPieceMoved() const {
        return hasMoved;
    }

    void setMoved() {
        hasMoved = true;
    }

    bool isKilled() const {
        return killed;
    }

    void setKilled() {
        killed = true;
    }
};




