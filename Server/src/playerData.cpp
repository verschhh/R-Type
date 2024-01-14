/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** playerData.cpp
*/

#include "../include/playerData.hpp"

int Player::nextId = 1;

/**
 * @brief Construct a new Player:: Player object
 *
 */

Player::Player() {
    id = nextId++;
}

/**
 * @brief Get the private variable "id"
 *
 * @return int Id of player
 */

int Player::getPlayerId() {
    return this->id;
}