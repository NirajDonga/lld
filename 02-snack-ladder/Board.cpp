#include "Board.hpp"
#include <cstdlib>

Board::Board(int sz, int jumps) {
    size = sz;
    addRandomJumps(jumps);
}

int Board::getJump(int cord) {
    if (jump.find(cord) != jump.end()) {
        return jump[cord];
    }
    return cord; 
}

void Board::addRandomJumps(int count) {
    for (int i = 0; i < count; i++) {
        int start = (rand() % (size - 2)) + 2; 
        int end = (rand() % (size - 2)) + 2;
        
        if (start != end && jump.find(start) == jump.end()) {
            jump[start] = end;
        }
    }
}