#pragma once
#include "Enums.hpp"

class Cell {
public:
    int row, col;
    Symbol* symbol;

    Cell();
    Cell(int r, int c);

    bool isEmpty();

    void setSymbol(Symbol* s);
    Symbol* getSymbol();
    
};
