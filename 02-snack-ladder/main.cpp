#include<iostream>
#include <ctime>
#include <cstdlib>
#include "Player.hpp"
#include "Game.hpp"

using namespace std;

int main() {
    srand(time(NULL)); // SEED the random number generator!

    Player* p1 = new Player("A");
    Player* p2 = new Player("B");
    Player* p3 = new Player("C");

    Game* game = new Game(100);

    game->addPlayer(p1);
    game->addPlayer(p2);
    game->addPlayer(p3);

    game->play();

    delete p1;
    delete p2;
    delete p3;
    delete game;

    return 0;
}