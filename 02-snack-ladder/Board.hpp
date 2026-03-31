#pragma once
#include <map>

class Board {
private:
    int size;
    std::map<int,int> jump;

public:
    Board(int sz);
    void addJump(int start, int end);
    int getJump(int cord);
    int getSize();
};