#include <cstdlib>
#include "Dice.hpp"

using namespace std;

Dice::Dice(int s) {
    sides = s;
}

int Dice::roll() {
    return (rand() % sides) + 1;
}