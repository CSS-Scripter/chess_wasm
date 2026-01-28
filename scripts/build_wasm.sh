mkdir -p build_wasm
cd build_wasm
emcmake cmake -DCMAKE_BUILD_TYPE=Release ..
emmake make -j$(nproc)
