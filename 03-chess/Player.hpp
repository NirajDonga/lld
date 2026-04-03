#pragma once

#include <string>

class Player {
private:
    std::string name;
    bool isWhite;

public:
    Player(const std::string& name, bool flag) : name(name), isWhite(flag) {}
    std::string getName() const {
        return name;
    }
    bool isWhiteSide() const {
        return isWhite;
    }
};