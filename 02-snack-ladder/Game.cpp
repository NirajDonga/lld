#include "Game.hpp"
#include <cstdlib> 
#include <iostream>

using namespace std;

Game::Game(Board* b, Dice* d) : board(b), dice(d) {
}

void Game::addPlayer(Player* p) {
    players.push(p);
}

void Game::play() {
    int boardSize = board->getSize();

    while(!players.empty()) {
        int num = dice->roll(); 
        Player* currPlayer = players.front(); 
        players.pop();

        int pos = currPlayer->getPosition();
        pos += num;

        if (pos <= boardSize) { 
            pos = board->getJump(pos);
            currPlayer->setPosition(pos);
        }

        if(currPlayer->getPosition() == boardSize) {
            cout << "Player " << currPlayer->getName() << " won the game!" << endl;
            break;
        }

        players.push(currPlayer);
    }
}