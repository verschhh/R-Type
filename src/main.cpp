/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main.cpp
*/

#include <iostream>
#include "ecs.hpp"

/** @file main.cpp
*/

/**
 * @brief Adds two integers.
 *
 * This function takes two integers as input and returns their sum.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return The sum of the two integers.
 */

int test(int a, int b) {
    return a + b;
}

/**
 * @brief The main function.
 *
 * This is the main function of the program. It calls the test function with
 * the values 2 and 4, and returns the result.
 *
 * @param ac The number of command-line arguments.
 * @param av The array of command-line arguments.
 * @return The result of the test function.
 */


int ecs() {
    Entity myEntity(42);
    size_t value = static_cast<size_t>(myEntity);
    size_t implicitValue = myEntity;

    std::cout << "Entity value: " << value << std::endl;
    std::cout << "Implicitly converted value: " << implicitValue << std::endl;

    return 0;
}

int main(int ac, char **av) {
    std::cout << "Hello";
    ecs();
    return test(1, 2);
}