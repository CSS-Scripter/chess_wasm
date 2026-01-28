export interface Board {
    whiteKing: bigint;
    whiteQueen: bigint;
    whiteRook: bigint;
    whiteBishop: bigint;
    whiteKnight: bigint;
    whitePawns: bigint;


    blackKing: bigint;
    blackQueen: bigint;
    blackRook: bigint;
    blackBishop: bigint;
    blackKnight: bigint;
    blackPawns: bigint;
}

export interface ChessModule {
    starting_board(): Board;
    get_piece_name(board: Board, field: string): string;
    rook_moves(square: string): string;
}

export default function createChessModule(): Promise<ChessModule>
