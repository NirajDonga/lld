#pragma once
#include <string>
#include "Enums.hpp"

class Player {
private:
    std::string name;
    Symbol playerSymbol;

public:
    Player(std::string playerName, Symbol s);
    std::string getname();
    Symbol* getSymbol();
};