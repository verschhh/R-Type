mkdir -p build && cd build
cmake ..
make && mv R-TypeServer .. && mv R-TypeClient .. 
cd .. && rm -rf build