#include<iostream>
#include "Game.hpp"

using namespace std;

Game::Game(int size, Player* p1, Player* p2) : board(size) {
    player1 = p1;
    player2 = p2;
    currPlayer = p1;
    strategies.push_back(new RowWin());
    strategies.push_back(new ColWin());
    strategies.push_back(new DiaWin());
}

bool Game::makeMove(int r, int c) {
    
    Symbol* symbol = currPlayer->getSymbol();

    bool move = board.moveDone(r, c, symbol);
    if(move) {
        for (WinningStratergies* strategy : strategies) {
            if (strategy->checkWin(&board)) {
                cout << currPlayer->getname() << " WINS THE GAME!" << endl;
                return true; 
            }
        }
        currPlayer = (currPlayer == player1) ? player2 : player1;
    }

    if(!move) {
        cout << "Already Occupied Cell" << r << " " << c << endl;
    }

    return move;
}