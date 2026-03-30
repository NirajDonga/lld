#include<iostream>
#include "Game.hpp"
#include "Stratergies/WinningStratergies.hpp"

using namespace std;

int main() {

    Player* p1 = new Player("A", Symbol('O'));
    Player* p2 = new Player("B", Symbol('X'));

    Game* game = new Game(3, p1, p2);
    game->makeMove(0, 0);
    game->makeMove(0, 1);
    game->makeMove(0, 2);
    game->makeMove(1, 1);
    game->makeMove(1, 2);
    game->makeMove(2, 1);

    game->board.display();

}