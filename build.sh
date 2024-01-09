mkdir -p build && cd build
cmake ..
make && mv R-TypeCommon ..
cd .. && rm -rf build