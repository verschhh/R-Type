# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(R-Type-Server VERSION 1.0)
project(R-Type-Client VERSION 1.0)
project(R-Type-ClientGraphique VERSION 1.0)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
# project(R-Type-Common VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target
# add_executable(R-TypeServer ./Server/src/main.cpp ./Server/src/InitServer.cpp ./Server/include/InitServer.hpp ./Server/src/UdpServer.cpp ./Server/include/UdpServer.hpp)
# add_executable()
add_executable(R-TypeCommon ./Client/src/main.cpp ./Client/src/Input.cpp ./Client/src/Missile.cpp ./Client/include/Sprite.hpp ./Client/include/Components.hpp ./Client/include/Input.hpp ./Client/include/Sound.hpp ./Client/include/IGraphics.hpp ./Client/include/Missile.hpp ./Client/include/HitBox.hpp ./Client/src/HitBox.cpp ./Client/include/Enemy.hpp ./Client/src/Enemy.cpp ./Client/include/Player.hpp ./Client/src/Player.cpp)

target_link_libraries(R-TypeCommon sfml-graphics sfml-audio)