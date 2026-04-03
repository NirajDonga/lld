#include <iostream>
#include "Bishop.hpp"
#include "ChessTypes.hpp"

// using namespace std;
bool Bishop::legalMove(const Position& from, const Position& to) const {
    if(abs(from.row - to.row) != abs(from.col - to.col)) {
        return false;
    }
    return true;
}
