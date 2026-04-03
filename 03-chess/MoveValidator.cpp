	
#include "MoveValidator.hpp"

bool MoveValidator::isValidMove(const Board& board, const Piece& piece, const Position& from, const Position& to) const {
    
    if(from.col > 7 || from.row > 7 || to.row < 0 || to.col < 0) {
        return false;
    }
    if(!piece.legalMove(from, to)) {
        return false;
    }

    if(isBlocked(board, from, to)) {
        return false;
    }

    return true;
}

bool MoveValidator::isBlocked(const Board& board, const Position& from, const Position& to) const {
    
    if (from.row == to.row && from.col == to.col) return false;
    Position cf = from;
    Position ct = to;

    if(cf.row > ct.row) cf.row--;
    else if(cf.row < ct.row) cf.row++;
    if(cf.col > ct.col) cf.col--;
    else if(cf.col < ct.col) cf.col++;
    
    while(cf.row != ct.row || cf.col != ct.col) {

        if(board.hasPiece(cf)) return true;

        if(cf.row > ct.row) cf.row--;
        else if(cf.row < ct.row) cf.row++;
        if(cf.col > ct.col) cf.col--;
        else if(cf.col < ct.col) cf.col++;
    
    }

    return false;

}