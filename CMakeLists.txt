# # Specify the minimum version of CMake required
# cmake_minimum_required(VERSION 3.10)

# # Set the project name and version
# project(R-Type VERSION 1.0)

# # Specify the C++ standard
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Add the executable target
# add_executable(R-Type ./src/main.cpp)


cmake_minimum_required(VERSION 3.10)

project(R-Type VERSION 1.0)

add_executable(R-Type
    ./src/main.cpp
)

target_include_directories(R-Type PRIVATE ./include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

