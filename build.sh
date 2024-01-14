if [ ! -d "vcpkg" ]; then
    git clone https://github.com/microsoft/vcpkg.git
else
    cd vcpkg
    git pull origin master
    cd ..
fi

cd vcpkg
./bootstrap-vcpkg.sh

./vcpkg install

cd ..

mkdir -p build && cd build
cmake ..
make && mv R-Type* ..
cd .. && rm -rf build