#pragma once

#include "../Board.hpp"

class WinningStratergies {
public:
    virtual bool checkWin(Board* board) = 0; 
    virtual ~WinningStratergies() = default; 
};

class RowWin : public WinningStratergies {
public: 
    bool checkWin(Board* board) override;
};

class ColWin : public WinningStratergies {
public: 
    bool checkWin(Board* board) override;
};

class DiaWin : public WinningStratergies {
public: 
    bool checkWin(Board* board) override;
};