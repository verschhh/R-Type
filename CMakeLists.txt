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
add_executable(R-TypeServer ./Server/src/main.cpp ./Server/src/playerData.cpp ./Server/include/playerData.hpp)
# add_executable(R-TypeClient ./Client/src/RTypeClientTest.cpp)
add_executable(R-TypeCommon
    ./Client/src/main.cpp
    ./Client/src/Enemy.cpp
    ./Client/src/HitBox.cpp
    ./Client/src/Input.cpp
    ./Client/src/Missile.cpp
    ./Client/src/Player.cpp
    ./Client/src/RTypeClientTest.cpp
    ./Client/include/Enemy.hpp
    ./Client/include/Button.hpp
    ./Client/include/Components.hpp
    ./Client/include/HitBox.hpp
    ./Client/include/IGraphics.hpp
    ./Client/include/Input.hpp
    ./Client/include/mainLoop.hpp
    ./Client/include/Missile.hpp
    ./Client/include/Player.hpp
    ./Client/include/Sound.hpp
    ./Client/include/Sprite.hpp
    )

target_link_libraries(R-TypeCommon
    sfml-graphics sfml-audio
    ${Boost_LIBRARIES}
    pthread
)


target_link_libraries(R-TypeServer
    ${Boost_LIBRARIES}
    pthread
)