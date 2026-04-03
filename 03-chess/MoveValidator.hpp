#pragma once

#include "ChessTypes.hpp"
#include "./Piece.hpp"
#include "Board.hpp"

class MoveValidator {
public:
	bool isValidMove(const Board& board ,const Piece& piece, const Position& from, const Position& to) const;
private:
	bool isBlocked(const Board& board, const Position& from, const Position& to) const;
};

