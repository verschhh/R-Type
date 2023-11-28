/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main.cpp
*/

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

int main(int ac, char **av) {
    int result = test(2, 4);
    return result;
}