# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(R-Type-Server VERSION 1.0)
project(R-Type-Client VERSION 1.0)
# project(R-Type-Common VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target
add_executable(R-TypeServer ./Server/src/main.cpp ./Server/src/InitServer.cpp ./Server/include/InitServer.hpp ./Server/src/UdpServer.cpp ./Server/include/UdpServer.hpp)
add_executable(R-TypeClient ./Client/src/RTypeClientTest.cpp)
# add_executable(R-TypeCommon ./Client/src/main.cpp ./Client/src/Window.cpp ./Client/include/Constants.hpp ./Client/include/Loopable.hpp ./Client/include/Window.hpp)