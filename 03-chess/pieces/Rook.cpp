#include <iostream>
#include "Rook.hpp"
#include "ChessTypes.hpp"

// using namespace std;
bool Rook::legalMove(const Position& from, const Position& to) const {
    int x = abs(from.row - to.row);
    int y = abs(from.col - to.col);

    if(x == 0 || y == 0) return true;
    return false;

}
