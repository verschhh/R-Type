# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(rtype_client)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (WIN32)
    find_program(conan_path conan)
    message(STATUS "Conan executable found at ${conan_path}")
    execute_process(COMMAND ${conan_path} install ${CMAKE_SOURCE_DIR} "-s" "compiler=Visual Studio" "-s" "compiler.version=16" "-s" "build_type=Debug" WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
else()
    add_definitions("-fPIC")
endif()


# Add the executable target
add_executable(rtype_client ./src/main.cpp)

# add the library
target_link_libraries(rtype_client sfml-graphics sfml-window sfml-system sfml-audio)