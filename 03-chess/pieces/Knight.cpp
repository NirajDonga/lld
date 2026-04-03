#include <iostream>
#include "Knight.hpp"
#include "ChessTypes.hpp"

// using namespace std;
bool Knight::legalMove(const Position& from, const Position& to) const {
    int x = abs(from.row - to.row);
    int y = abs(from.col - to.col);
    
    if(x + y == 3 && x != 0 && y != 0) return true;

    return false;
}
