<script setup lang="ts">
import BoardView from './views/BoardView.vue';

</script>

<template>
  <div>
    <Suspense>
      <BoardView></BoardView>
    </Suspense>
  </div>
</template>

<style scoped></style>
