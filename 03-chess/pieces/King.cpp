#include <iostream>
#include "King.hpp"
#include "ChessTypes.hpp"

// using namespace std;
bool King::legalMove(const Position& from, const Position& to) const {
    if(abs(from.row - to.row) < 2 && abs(from.col - to.col) < 2) {
        return true;
    }
    return false;
}
