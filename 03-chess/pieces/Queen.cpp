#include <iostream>
#include "Queen.hpp"
#include "ChessTypes.hpp"

// using namespace std;
bool Queen::legalMove(const Position& from, const Position& to) const {
    int x = abs(from.row - to.row);
    int y = abs(from.col - to.col);

    if(x == y || x == 0 || y == 0) return true;
    return false;

}
