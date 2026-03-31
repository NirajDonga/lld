#pragma once
#include <map>

class Board {
private:
    int size;
    std::map<int,int> jump;

public:
    Board(int sz, int jumps);
    int getJump(int cord);
    
private:
    void addRandomJumps(int count);
};