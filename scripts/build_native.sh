mkdir -p build_native
cd build_native
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)
