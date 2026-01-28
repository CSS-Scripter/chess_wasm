<script setup lang="ts">
import { ref, onMounted } from "vue";
import createChessModule, { type ChessModule } from '@/wasm/libchess.js';

const input = ref("d4");
const moves = ref("");

onMounted(async () => {
    const chess: ChessModule = await createChessModule();
    moves.value = chess.rook_moves(input.value);
})

</script>

<template>
    <div>
        <h2>Rook Moves</h2>
        <p>From: {{ input }}</p>
        <p>Moves: {{ moves }}</p>
    </div>
</template>
