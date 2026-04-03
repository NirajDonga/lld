#pragma once

#include "ChessTypes.hpp"
#include "./Piece.hpp"

class MoveValidator {
public:
	bool isValidMove(const Piece& piece, const Position& from, const Position& to) const {
		return piece.legalMove(from, to);
	}
};
