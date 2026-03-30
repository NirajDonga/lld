#include "Cell.hpp"

Cell::Cell() : row(-1), col(-1), symbol(nullptr) {}
Cell::Cell(int r, int c) : row(r), col(c), symbol(nullptr) {}

bool Cell::isEmpty() {
    return symbol == nullptr;
}

void Cell::setSymbol(Symbol* s) {
    symbol = s;
}

Symbol* Cell::getSymbol() {
    return symbol;
}
