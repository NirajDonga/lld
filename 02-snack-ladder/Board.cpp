#include "Board.hpp"
#include <cstdlib>

Board::Board(int sz) {
    size = sz;
}

void Board::addJump(int start, int end) {
    jump[start] = end;
}

int Board::getJump(int cord) {
    if (jump.find(cord) != jump.end()) {
        return jump[cord];
    }
    return cord; 
}

int Board::getSize() {
    return size;
}