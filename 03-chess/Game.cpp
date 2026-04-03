

#include "Game.hpp"
#include "MoveValidator.hpp"

Game::Game(Player* p1, Player* p2) {
    if(p1->isWhiteSide()) currTurn = p1;
    else currTurn = p2;
}

bool Game::canMove(const Position& from, const Position& to) {
    if (!board.hasPiece(from)) return false;

    Piece& piece = board.getPiece(from);
    return mv.isValidMove(piece, from, to);
}