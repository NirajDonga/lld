#pragma once

#include <string>

class Player {
private:
    std::string name;
    bool isWhite;

public:
    Player(const std::string& name, bool flag);
    std::string getName() const;
    bool isWhiteSide() const;
};