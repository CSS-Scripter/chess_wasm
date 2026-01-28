<script setup lang="ts">
import { ref, watch } from "vue";
import { type Board } from '@/wasm/libchess.js';
import { useChessStore } from "@/stores/chess";

const chess = useChessStore();
await chess.init();
const input = ref("");
const board = ref<Board>(chess.get().starting_board());
const piece = ref("");

watch(input, (field) => {
    const chessModule = chess.get();
    piece.value = chessModule.get_piece_name(board.value, field)
})

</script>

<template>
    <div>
        <input type="text" name="field" id="field" v-model="input">
        <p>Field {{ input }} contains piece {{ piece }}</p>
    </div>
</template>
