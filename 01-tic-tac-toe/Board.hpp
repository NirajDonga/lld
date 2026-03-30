#pragma once
#include "Cell.hpp"
#include <vector>

class Board {
private:
    int size;
    std::vector<std::vector<Cell>> grid;

public:
    Board(int n);
    int getSize();
    bool moveDone(int r, int c, Symbol* s);
    Symbol* getSymbolAt(int r, int c);
    void display();
};