/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main.cpp
*/

#include <iostream>
#include "Registry.hpp"
#include "Components.hpp"

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

#include <optional>

void test(Registry registry)
{
    registry.register_component<Position>();
    Entity myEntity = registry.spawn_entity();
    Position initialPosition = {1.1f, 2.2f};

    registry.add_component(myEntity, std::move(initialPosition));

    auto &positionArray = registry.get_components<Position>();

    Position myEntityPosition = positionArray[myEntity].value();
    std::cout << "Updated position for entity " << static_cast<std::size_t>(myEntity)
              << ": x = " << myEntityPosition.x << ", y = " << myEntityPosition.y << std::endl;

    myEntityPosition.x += 20;

    registry.add_component(myEntity, std::move(myEntityPosition));
    auto &secondArray = registry.get_components<Position>();
    Position mySecondPosition = secondArray[myEntity].value();
    std::cout << "Updated position for entity " << static_cast<std::size_t>(myEntity)
              << ": x = " << mySecondPosition.x << ", y = " << mySecondPosition.y << std::endl;


}

int main() {
    Registry registry;

    test(registry);


    // Entity myEntity = registry.spawn_entity();
    // Position initialPosition = {0.0f, 0.0f};
    // registry.add_component(myEntity, std::move(initialPosition));

    // std::optional<Position>& maybePosition = positionArray[myEntity];

    // if (maybePosition) {
    //     Position& myEntityPosition = *maybePosition;

    //     myEntityPosition.x = 10.0f;
    //     myEntityPosition.y = 5.0f;

    //     std::cout << "Updated position for entity " << static_cast<std::size_t>(myEntity)
    //           << ": x = " << myEntityPosition.x << ", y = " << myEntityPosition.y << std::endl;
    // } else {
    //     std::cerr << "Position component does not exist for entity " << static_cast<std::size_t>(myEntity) << std::endl;
    // }

    return 0;
}