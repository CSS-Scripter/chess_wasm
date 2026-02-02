<script setup lang="ts">
import { computed, ref, type Component } from "vue";
import { type Board } from '@/wasm/libchess.js';
import { useChessStore } from "@/stores/chess";
import BlackKingIcon from "@/components/icons/pieces/BlackKingIcon.vue";
import BlackQueenIcon from "@/components/icons/pieces/BlackQueenIcon.vue";
import BlackBishopIcon from "@/components/icons/pieces/BlackBishopIcon.vue";
import BlackKnightIcon from "@/components/icons/pieces/BlackKnightIcon.vue";
import BlackRookIcon from "@/components/icons/pieces/BlackRookIcon.vue";
import BlackPawnIcon from "@/components/icons/pieces/BlackPawnIcon.vue";
import { EMPTY_PIECE, type Piece, type PieceColor, type PieceType } from "@/types/piece.type";
import WhitePawnIcon from "@/components/icons/pieces/WhitePawnIcon.vue";
import WhiteRookIcon from "@/components/icons/pieces/WhiteRookIcon.vue";
import WhiteKnightIcon from "@/components/icons/pieces/WhiteKnightIcon.vue";
import WhiteBishopIcon from "@/components/icons/pieces/WhiteBishopIcon.vue";
import WhiteKingIcon from "@/components/icons/pieces/WhiteKingIcon.vue";
import WhiteQueenIcon from "@/components/icons/pieces/WhiteQueenIcon.vue";
import EmptyPieceIcon from "@/components/icons/pieces/EmptyPieceIcon.vue";

const COLS = 'abcdefgh'.split('').reverse();
const ROWS = '12345678'.split('');

const playingAsBlack = true;

const pieceIcons: Record<PieceColor, Record<PieceType, Component>> = {
    'BLACK': {
        'PAWN'  : BlackPawnIcon,
        'ROOK'  : BlackRookIcon,
        'KNIGHT': BlackKnightIcon,
        'BISHOP': BlackBishopIcon,
        'KING'  : BlackKingIcon,
        'QUEEN' : BlackQueenIcon,
        'EMPTY' : EmptyPieceIcon,
    },
    'WHITE': {
        'PAWN'  : WhitePawnIcon,
        'ROOK'  : WhiteRookIcon,
        'KNIGHT': WhiteKnightIcon,
        'BISHOP': WhiteBishopIcon,
        'KING'  : WhiteKingIcon,
        'QUEEN' : WhiteQueenIcon,
        'EMPTY' : EmptyPieceIcon,
    },
    'EMPTY': {
        'PAWN'  : EmptyPieceIcon,
        'ROOK'  : EmptyPieceIcon,
        'KNIGHT': EmptyPieceIcon,
        'BISHOP': EmptyPieceIcon,
        'KING'  : EmptyPieceIcon,
        'QUEEN' : EmptyPieceIcon,
        'EMPTY' : EmptyPieceIcon,        
    }
}

const chess = useChessStore();
await chess.init();

const board = ref<Board>(chess.get().starting_board());
const boardPieces = computed<Piece[]>(() => {
    const start = Date.now();
    const b = [] as Piece[];
    for (const row of ROWS) {
        for (const col of COLS) {
            const piece = chess.get().get_piece_name(board.value, col + row);
            if (piece === 'EMPTY') {
                b.push(EMPTY_PIECE);
            } else {
                b.push({
                    color: piece.split(' ')[0],
                    type: piece.split(' ')[1]
                } as Piece);
            }
        }
    }
    const duration = Date.now() - start;
    console.log(`recalculated new board pieces, took ${duration}ms`);
    return b;
});

function indexToTileName(index: number) {
    const col = index % COLS.length;
    const row = Math.floor(index / ROWS.length);

    return `${COLS[col]}${ROWS[row]}`
}

function tileClicked(tile: number) {
    const tileName = indexToTileName(tile);
    console.log(`${tileName} clicked`);
}

function legendRows(): string[] {
    return (playingAsBlack) ? ROWS : ROWS.slice().reverse();
}

function legendCols(): string[] {
    return (playingAsBlack) ? COLS : COLS.slice().reverse();
}


</script>

<template>
    <div class="board" :class="{'white-side': !playingAsBlack}">
        <div class="legend-rows">
            <div v-for="row of legendRows()" :key="row" class="legend">
                {{ row }}
            </div>
        </div>
        <div class="legend-cols">
            <div v-for="col of legendCols()" :key="col" class="legend">
                {{ col }}
            </div>
        </div>
        <div class="tiles">
            <div
                v-for="piece, i of boardPieces"
                :key="indexToTileName(i)"
                class="tile"
                :class="{tinted: (i + Math.floor(i / 8)) % 2 == 1}"
                @click="tileClicked(i)"
            >
                <component :is="pieceIcons[piece.color][piece.type]"></component>
            </div>
        </div>
    </div>
</template>

<style>
.board {
    display: grid;
    grid-template-columns: 1fr 8fr;
    grid-template-rows: 8fr 1fr;

    grid-template-areas: "lr t" "_ lc";

    width: 600px;
    max-width: 600px;
    aspect-ratio: 1;
    gap: 8px;
    padding: 1em;

    user-select: none;
}

.tiles {
    grid-area: t;

    display: grid;
    grid-template-rows: repeat(8, 1fr);
    grid-template-columns: repeat(8, 1fr);
    gap: 2px;
}

.legend-rows {
    grid-area: lr;
    display: grid;
    grid-template-rows: repeat(8, 1fr);
}


.legend-cols {
    grid-area: lc;
    display: grid;
    grid-template-columns: repeat(8, 1fr);
    grid-template-rows: 1fr;
}

.legend {
    font-size: 2em;
    text-transform: capitalize;
    text-align: center;
}

.board > .tiles > .tile {
    display: block;
    width: 100%;
    height: 100%;
    box-sizing: border-box;
    border: 1px solid black;
    background: rgb(191, 214, 183);
    text-align: center;
    aspect-ratio: 1;
}

.board > .tiles > .tile > * {
    display: block;
    width: 100%;
    height: 100%;
}

.board > .tiles > .tile.tinted {
    background: rgb(26, 121, 88);
}

.board.white-side > .tiles,
.board.white-side > .tiles > .tile {
    transform: rotate(180deg);
}

.board > .tiles > .tile:hover {
    background: rgb(116, 135, 114);
}

.board > .tiles > .tile.tinted:hover {
    background: rgb(18, 87, 63);
}

</style>
