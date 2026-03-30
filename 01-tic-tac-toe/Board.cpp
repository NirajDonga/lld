#include<iostream>
#include "Board.hpp"

using namespace std;

Board::Board(int n) : size(n), grid(n, vector<Cell>(n)) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            grid[i][j] = Cell(i, j);
        }
    }
}

int Board::getSize() { 
    return size; 
}

Symbol* Board::getSymbolAt(int r, int c) {
    if (r >= size || r < 0 || c >= size || c < 0) {
        return nullptr;
    }
    return grid[r][c].getSymbol();
}

bool Board::moveDone(int r, int c, Symbol* s) {
    if (r >= size || r < 0 || c >= size || c < 0) {
        return false;
    }
    if(!grid[r][c].isEmpty()) return false;
    grid[r][c].setSymbol(s);
    return true;
}

void Board::display() {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            Symbol* s = grid[i][j].getSymbol();
            
            if (s == nullptr) {
                cout << "- ";
            } else {
                cout << static_cast<char>(*s) << " ";
            }
        }
        cout << endl;
    }
}