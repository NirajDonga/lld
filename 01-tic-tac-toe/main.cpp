#include<iostream>
#include "Game.hpp"
#include "Stratergies/WinningStratergies.hpp"

using namespace std;

int main() {

    Player* p1 = new Player("A", Symbol('O'));
    Player* p2 = new Player("B", Symbol('X'));

    Player* p3 = new Player("A", Symbol('X'));
    Player* p4 = new Player("B", Symbol('O'));

    Game* game1 = new Game(3, p1, p2);
    Game* game2 = new Game(3, p3, p4);
    game1->makeMove(0, 0);
    game2->makeMove(1, 2);
    game1->makeMove(0, 1);
    game2->makeMove(2, 1);
    game1->makeMove(0, 2);
    game2->makeMove(2, 2);
    game1->makeMove(1, 1);
    game2->makeMove(0, 1);
    game1->makeMove(1, 2);
    game2->makeMove(0, 0);
    game1->makeMove(2, 1);
    game2->makeMove(0, 2);
    game2->makeMove(1, 1);

    game1->board.display();
    game2->board.display();

    delete game1;
    delete p1;
    delete p2;
    
    delete game2;
    delete p3;
    delete p4;


    return 0;
}