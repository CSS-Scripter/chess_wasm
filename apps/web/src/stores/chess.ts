import { defineStore } from "pinia";
import createChessModule, { type ChessModule } from "@/wasm/libchess";

export const useChessStore = defineStore("chess", () => {
  let chessModule: ChessModule | null = null;
  let initPromise: Promise<ChessModule> | null = null;

  async function init(): Promise<ChessModule> {
    if (chessModule) {
      return chessModule;
    }

    if (!initPromise) {
      initPromise = createChessModule().then((module) => {
        chessModule = module;
        return module;
      });
    }

    return initPromise;
  }

  function get(): ChessModule {
    if (!chessModule) {
      throw new Error("Chess module not initialized. Call init() first.");
    }
    return chessModule;
  }

  return {
    init,
    get,
  };
});
