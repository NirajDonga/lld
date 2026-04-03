
#include "Board.hpp"
#include "Piece.hpp"

#include "pieces/Bishop.hpp"
#include "pieces/King.hpp"
#include "pieces/Knight.hpp"
#include "pieces/Pawn.hpp"
#include "pieces/Queen.hpp"
#include "pieces/Rook.hpp"

namespace {
bool isValidPosition(const Position& position) {
    return position.row >= 0 && position.row < 8 && position.col >= 0 && position.col < 8;
}

void clearGrid(std::vector<std::vector<Piece*>>& grid) {
    for (auto& row : grid) {
        for (Piece*& piece : row) {
            delete piece;
            piece = nullptr;
        }
    }
}
} // namespace

Board::~Board() {
    clearGrid(grid);
}

void Board::initializeBoard() {
    clearGrid(grid);

    for (int col = 0; col < 8; ++col) {
        grid[1][col] = new Pawn(false);
        grid[6][col] = new Pawn(true);
    }

    grid[0][0] = new Rook(true);
    grid[0][1] = new Knight(true);
    grid[0][2] = new Bishop(true);
    grid[0][3] = new Queen(true);
    grid[0][4] = new King(true);
    grid[0][5] = new Bishop(true);
    grid[0][6] = new Knight(true);
    grid[0][7] = new Rook(true);

    grid[7][0] = new Rook(false);
    grid[7][1] = new Knight(false);
    grid[7][2] = new Bishop(false);
    grid[7][3] = new Queen(false);
    grid[7][4] = new King(false);
    grid[7][5] = new Bishop(false);
    grid[7][6] = new Knight(false);
    grid[7][7] = new Rook(false);
}

bool Board::move(const Position& from, const Position& to) {
    if (!isValidPosition(from) || !isValidPosition(to)) {
        return false;
    }

    Piece* movingPiece = grid[from.row][from.col];
    if (movingPiece == nullptr) {
        return false;
    }

    Piece* destinationPiece = grid[to.row][to.col];
    if (destinationPiece != nullptr && destinationPiece->isWhite() == movingPiece->isWhite()) {
        return false;
    }

    if (destinationPiece != nullptr) {
        destinationPiece->setKilled();
        delete destinationPiece;
    }

    grid[to.row][to.col] = movingPiece;
    grid[from.row][from.col] = nullptr;
    movingPiece->setMoved();

    return true;
}

Piece* Board::getPiece(const Position& position) {
    if (!isValidPosition(position)) {
        return nullptr;
    }

    return grid[position.row][position.col];
}

const Piece* Board::getPiece(const Position& position) const {
    if (!isValidPosition(position)) {
        return nullptr;
    }

    return grid[position.row][position.col];
}

bool Board::hasPiece(const Position& position) const {
    if (!isValidPosition(position)) {
        return false;
    }

    return grid[position.row][position.col] != nullptr;
}