#pragma once
#include<string>

class Player {
private:
    std::string name;
    int position;

public:
    Player(std::string name);
    std::string getName();
    int getPosition();
    void setPosition(int pos);  
};