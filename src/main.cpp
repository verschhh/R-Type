/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main.cpp
*/

#include <iostream>
#include "Entity.hpp"
#include "Sparse.hpp"

/** @file main.cpp
*/



int ecs() {
    Entity myEntity(42);
    size_t value = static_cast<size_t>(myEntity);
    size_t implicitValue = myEntity;

    std::cout << "Entity value: " << value << std::endl;
    std::cout << "Implicitly converted value: " << implicitValue << std::endl;

    return 0;
}

int main() {
    // Test default constructor
    Sparse_array<int> sparseArray;

    sparseArray[1] = 42;
    sparseArray[3] = 10;

    // Sparse_array<int> copiedArray(sparseArray);

    // for (const auto& value : copiedArray) {
    //     if (value.has_value()) {
    //         std::cout << value.value() << " ";
    //     } else {
    //         std::cout << "N/A ";
    //     }
    // }
    // std::cout << std::endl;
    return 0;
}