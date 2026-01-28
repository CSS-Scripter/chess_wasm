export interface ChessModule {
    rook_moves(square: string): string;
}

export function createChessModule(): Promise<ChessModule>
export default function createChessModule(): Promise<ChessModule>
