#pragma once

#include <cstdint>
#include <string>

struct Board {
    uint64_t whiteKing   {};
    uint64_t whiteQueen  {};
    uint64_t whiteRook   {};
    uint64_t whiteBishop {};
    uint64_t whiteKnight {};
    uint64_t whitePawn   {};

    uint64_t blackKing   {};
    uint64_t blackQueen  {};
    uint64_t blackRook   {};
    uint64_t blackBishop {};
    uint64_t blackKnight {};
    uint64_t blackPawn   {};
};

Board starting_board();
std::string get_piece_name(const Board& board, std::string field);
