#include <iostream>
#include "WinningStratergies.hpp"

using namespace std;

bool RowWin::checkWin(Board* board) {
    int n = board->getSize();
    for (int i = 0; i < n; i++) {
        Symbol* firstSymbol = board->getSymbolAt(i, 0);
        if (firstSymbol == nullptr) continue;
        
        bool win = true;
        for (int j = 1; j < n; j++) {
            Symbol* currentSymbol = board->getSymbolAt(i, j);
            if (currentSymbol == nullptr || *currentSymbol != *firstSymbol) {
                win = false;
                break;
            }
        }
        if (win) {
            cout << "Win on row" << endl;
            return true;
        }
    }
    return false;
}

bool ColWin::checkWin(Board* board) {
    int n = board->getSize();
    for (int j = 0; j < n; j++) {
        Symbol* firstSymbol = board->getSymbolAt(0, j);
        if (firstSymbol == nullptr) continue;
        
        bool win = true;
        for (int i = 1; i < n; i++) {
            Symbol* currentSymbol = board->getSymbolAt(i, j);
            if (currentSymbol == nullptr || *currentSymbol != *firstSymbol) {
                win = false;
                break;
            }
        }
        if (win) {
            cout << "Win on col" << endl;
            return true;
        }
    }
    return false;
}

bool DiaWin::checkWin(Board* board) {
    int n = board->getSize();
    
    Symbol* mainDiaSymbol = board->getSymbolAt(0, 0);
    bool mainWin = (mainDiaSymbol != nullptr);
    if (mainWin) {
        for (int i = 1; i < n; i++) {
            Symbol* currentSymbol = board->getSymbolAt(i, i);
            if (currentSymbol == nullptr || *currentSymbol != *mainDiaSymbol) {
                mainWin = false;
                break;
            }
        }
        if (mainWin) {
            cout << "Win on dia" << endl;
            return true;
        }
    }

    Symbol* antiDiaSymbol = board->getSymbolAt(0, n - 1);
    bool antiWin = (antiDiaSymbol != nullptr);
    if (antiWin) {
        for (int i = 1; i < n; i++) {
            Symbol* currentSymbol = board->getSymbolAt(i, n - 1 - i);
            if (currentSymbol == nullptr || *currentSymbol != *antiDiaSymbol) {
                antiWin = false;
                break;
            }
        }
        if (antiWin) {
            cout << "Win on antidia" << endl;
            return true;
        }
    }

    return false;
}