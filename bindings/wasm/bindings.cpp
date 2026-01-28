// bindings/wasm/bindings.cpp
#include <emscripten/bind.h>
#include "chess.h"
#include "board.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(chess) {
    value_object<Board>("Board")
        .field("whiteKing", &Board::whiteKing)
        .field("whiteQueen", &Board::whiteQueen)
        .field("whiteRook", &Board::whiteRook)
        .field("whiteBishop", &Board::whiteBishop)
        .field("whiteKnight", &Board::whiteKnight)
        .field("whitePawn", &Board::whitePawn)
        .field("blackKing", &Board::blackKing)
        .field("blackQueen", &Board::blackQueen)
        .field("blackRook", &Board::blackRook)
        .field("blackBishop", &Board::blackBishop)
        .field("blackKnight", &Board::blackKnight)
        .field("blackPawn", &Board::blackPawn);


    function("starting_board", &starting_board);
    function("rook_moves", &rook_moves);
    function("get_piece_name", &get_piece_name);
}
