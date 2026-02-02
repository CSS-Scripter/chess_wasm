export type PieceType = 
    | 'PAWN'
    | 'ROOK'
    | 'KNIGHT'
    | 'BISHOP'
    | 'QUEEN'
    | 'KING'
    | 'EMPTY'
;

export type PieceColor =
    | 'WHITE'
    | 'BLACK'
    | 'EMPTY'
;


export interface Piece {
    type: PieceType,
    color: PieceColor,
}

export const EMPTY_PIECE: Piece = {
    type: 'EMPTY',
    color: 'EMPTY'
};
