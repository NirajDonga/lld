

#include "Game.hpp"
#include "MoveValidator.hpp"

Game::Game(Player* p1, Player* p2) {
    this->p1 = p1;
    this->p2 = p2;
    board.initializeBoard();

    if(p1->isWhiteSide()) currTurn = p1;
    else currTurn = p2;
}

bool Game::canMove(const Position& from, const Position& to) {
    if (!board.hasPiece(from)) return false;

    Piece* piece = board.getPiece(from);
    if (piece == nullptr) {
        return false;
    }

    if(piece->isWhite() != currTurn->isWhiteSide()) {
        return false;
    } 

    return mv.isValidMove(board, *piece, from, to);
}