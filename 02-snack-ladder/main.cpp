#include<iostream>
#include <ctime>
#include <cstdlib>
#include "Player.hpp"
#include "Game.hpp"

using namespace std;

int main() {
    srand(time(NULL)); // SEED the random number generator!

    Dice* dice = new Dice(6);

    int boardSize = 100;
    Board* board = new Board(boardSize);

    int jumpCount = (rand() % ((boardSize / 3) + 1)) + (boardSize / 3);
    for (int i = 0; i < jumpCount; i++) {
        int start = (rand() % (boardSize - 2)) + 2;
        int end = (rand() % (boardSize - 2)) + 2;
        if (start != end) {
            board->addJump(start, end);
        }
    }

    Game* game = new Game(board, dice);

    Player* p1 = new Player("A");
    Player* p2 = new Player("B");
    Player* p3 = new Player("C");

    game->addPlayer(p1);
    game->addPlayer(p2);
    game->addPlayer(p3);

    game->play();

    delete p1;
    delete p2;
    delete p3;
    delete board;
    delete dice;
    delete game;

    return 0;
}