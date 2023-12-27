# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(R-Type-Server VERSION 1.0)
project(R-Type-Client VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target
add_executable(R-TypeServer ./server/src/main.cpp ./server/src/UdpServer.cpp ./server/include/UdpServer.hpp)
add_executable(R-TypeClient ./client/src/RTypeClientTest.cpp)
