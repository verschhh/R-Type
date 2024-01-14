mkdir -p build && cd build
cmake ..
make && mv R-Type* ..
cd .. && rm -rf build