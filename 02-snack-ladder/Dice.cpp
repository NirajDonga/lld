#include <cstdlib>
#include "Dice.hpp"

using namespace std;

int Dice::roll() {
    return (rand() % 6) + 1;
}