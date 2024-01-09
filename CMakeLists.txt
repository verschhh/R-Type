# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(R-Type-Server VERSION 1.0)
project(R-Type-Client VERSION 1.0)
project(R-Type-ClientGraphique VERSION 1.0)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
# project(R-Type-Common VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target
add_executable(R-TypeServer ./Server/src/Server.cpp ./Server/src/Parser.cpp ./Server/include/Parser.hpp ./Server/include/Server.hpp ./Engine/Network/Network.hpp ./Engine/Network/NLib.hpp)
add_executable(R-TypeClient ./Client/src/RTypeClientTest.cpp)
#add_executable(R-TypeCommon ./Client/src/main.cpp ./Client/include/Window.hpp ./Client/include/Sound.hpp ./Client/include/Sprite.hpp ./Client/include/Input.hpp)

#target_link_libraries(R-TypeCommon sfml-graphics sfml-audio)