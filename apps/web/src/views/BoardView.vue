<script setup lang="ts">
import { computed, ref } from "vue";
import { type Board } from '@/wasm/libchess.js';
import { useChessStore } from "@/stores/chess";

const COLS = 'abcdefgh'.split('').reverse();
const ROWS = '12345678'.split('');

const playingAsBlack = false;

const pieceIcons: Record<string, string> = {
    'BLACK PAWN'  : '♟',
    'BLACK ROOK'  : '♜',
    'BLACK KNIGHT': '♞',
    'BLACK BISHOP': '♝',
    'BLACK QUEEN' : '♛',
    'BLACK KING'  : '♚',

    'WHITE PAWN'  : '♙',
    'WHITE ROOK'  : '♖',
    'WHITE KNIGHT': '♘',
    'WHITE BISHOP': '♗',
    'WHITE QUEEN' : '♕',
    'WHITE KING'  : '♔',

    'EMPTY': ''
}

const chess = useChessStore();
await chess.init();
const board = ref<Board>(chess.get().starting_board());
const boardPieces = computed(() => {
    const start = Date.now();
    const b = [];
    for (const row of ROWS) {
        for (const col of COLS) {
            b.push(chess.get().get_piece_name(board.value, col + row));
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


</script>

<template>
    <div class="board" :class="{'white-side': !playingAsBlack}">
        <div
            v-for="boardPiece, i of boardPieces"
            :key="indexToTileName(i)"
            class="tile"
            :class="{tinted: (i + Math.floor(i / 8)) % 2 == 1}"
            @click="tileClicked(i)"
        >{{ pieceIcons[boardPiece] }}</div>
    </div>
</template>

<style>
.board {
    display: grid;
    grid-template-columns: repeat(8, 1fr);
    grid-template-rows: repeat(8, 1fr);

    width: 600px;
    height: 600px;
    gap: 8px;
    padding: 1em;

    user-select: none;
}

.board > .tile {
    display: block;
    width: 100%;
    height: 100%;
    box-sizing: border-box;
    border: 1px solid black;
    background: rgb(220, 200, 200);
    font-size: 32px;
    text-align: center;
    padding-top: 12px;
}

.board > .tile.tinted {
    background: rgba(80, 20, 20);
}

.board.white-side,
.board.white-side > .tile {
    transform: rotate(180deg);
}

.board > .tile:hover {
    background: rgb(200, 180, 180);
}

.board > .tile.tinted:hover {
    background: rgba(100, 40, 40);
}

</style>
