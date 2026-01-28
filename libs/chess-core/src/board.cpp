#include "board.h"
#include "constants.h"

/**
 * HEX TO BINARY REFERENCE
 * 0 | 0000  -  8 | 1000
 * 1 | 0001  -  9 | 1001
 * 2 | 0010  -  A | 1010
 * 3 | 0011  -  B | 1011
 * 4 | 0100  -  C | 1100
 * 5 | 0101  -  D | 1101
 * 6 | 0110  -  E | 1110
 * 7 | 0111  -  F | 1111
 * 
 * In hexadecimal notation, every 2 digits is 1 row.
 * Board assumes largest bit is a1, smallest bit is h8
 */

Board starting_board() {
    Board b{};

    b.whiteRook   = ROW_1 & (COL_A | COL_H);
    b.whiteKnight = ROW_1 & (COL_B | COL_G);
    b.whiteBishop = ROW_1 & (COL_C | COL_F);
    b.whiteQueen  = ROW_1 & (COL_D);
    b.whiteKing   = ROW_1 & (COL_E);
    b.whitePawn   = ROW_2;

    b.blackRook   = ROW_8 & (COL_A | COL_H);
    b.blackKnight = ROW_8 & (COL_B | COL_G);
    b.blackBishop = ROW_8 & (COL_C | COL_F);
    b.blackQueen  = ROW_8 & (COL_D);
    b.blackKing   = ROW_8 & (COL_E);
    b.blackPawn   = ROW_7;

    return b;
}


uint64_t encode_row(char row) {
    switch (row) {
        case '1': return ROW_1;
        case '2': return ROW_2;
        case '3': return ROW_3;
        case '4': return ROW_4;
        case '5': return ROW_5;
        case '6': return ROW_6;
        case '7': return ROW_7;
        case '8': return ROW_8;
        default:  return 0ULL;
    }
}

uint64_t encode_column(char column) {
    switch (column) {
        case 'a': return COL_A;
        case 'b': return COL_B;
        case 'c': return COL_C;
        case 'd': return COL_D;
        case 'e': return COL_E;
        case 'f': return COL_F;
        case 'g': return COL_G;
        case 'h': return COL_H;
        default:  return 0ULL;
    }
}


std::string get_piece_name(const Board& board, std::string field) {
    if (field.length() != 2) {
        return "INVALID";
    }

    char col = field[0];
    char row = field[1];

    uint64_t position = encode_column(col) & encode_row(row);
    if (position == 0) {
        return "INVALID";
    }

    if ((board.whiteRook   & position) > 0) return "WHITE ROOK";
    if ((board.whiteKnight & position) > 0) return "WHITE KNIGHT";
    if ((board.whiteBishop & position) > 0) return "WHITE BISHOP";
    if ((board.whiteQueen  & position) > 0) return "WHITE QUEEN";
    if ((board.whiteKing   & position) > 0) return "WHITE KING";
    if ((board.whitePawn   & position) > 0) return "WHITE PAWN";

    if ((board.blackRook   & position) > 0) return "BLACK ROOK";
    if ((board.blackKnight & position) > 0) return "BLACK KNIGHT";
    if ((board.blackBishop & position) > 0) return "BLACK BISHOP";
    if ((board.blackQueen  & position) > 0) return "BLACK QUEEN";
    if ((board.blackKing   & position) > 0) return "BLACK KING";
    if ((board.blackPawn   & position) > 0) return "BLACK PAWN";

    return "EMPTY";
}
