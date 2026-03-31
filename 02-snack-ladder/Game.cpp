#include "Game.hpp"
#include <cstdlib> 
#include <iostream>

using namespace std;

Game::Game(int sz) : board(sz, (rand() % ((sz / 3) + 1)) + (sz / 3)), dice() {
    boardSize = sz; // Store sz so we can check for a win in play()
}

void Game::addPlayer(Player* p) {
    players.push(p);
}

void Game::play() {

    while(!players.empty()) {
        int num = dice.roll(); 
        Player* currPlayer = players.front(); 
        players.pop();

        int pos = currPlayer->getPosition();
        pos += num;

        if (pos <= boardSize) { 
            pos = board.getJump(pos);
            currPlayer->setPosition(pos);
        }

        if(currPlayer->getPosition() == boardSize) {
            cout << "Player " << currPlayer->getName() << " won the game!" << endl;
            break;
        }

        // cout << currPlayer->getName() << endl;

        players.push(currPlayer);
    }


}