#include <iostream>
#include "Pawn.hpp"
#include "ChessTypes.hpp"

// using namespace std;
bool Pawn::legalMove(const Position& from, const Position& to) const {
    int x = abs(from.row - to.row);
    int y = abs(from.col - to.col);

    if(y == 0) {
        if(x == 1) return true;
    }
    if(y == 1) {
        if(x == 1) return true;
    }
    return false;

}
