/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Input.cpp
*/

#include "../include/Input.hpp"

float Input::moveLeft(float pos, float speed) {
    /**
     * @brief Moves the player to the left
     * @param pos : the player's position
     * @param speed : the player's speed
     * @return the new position
     */
    return pos - speed;
}

float Input::moveRight(float pos, float speed) {
    /**
     * @brief Moves the player to the right
     * @param pos : the player's position
     * @param speed : the player's speed
     * @return the new position
     */
    return pos + speed;
}

float Input::moveUp(float pos, float speed) {
    /**
     * @brief Moves the player to the top
     * @param pos : the player's position
     * @param speed : the player's speed
     * @return the new position
     */
    return pos - speed;
}

float Input::moveDown(float pos, float speed) {
    /**
     * @brief Moves the player to the bottom
     * @param pos : the player's position
     * @param speed : the player's speed
     * @return the new position
     */
    return pos + speed;
}