/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** playerData.cpp
*/

#include "../include/playerData.hpp"

int Player::nextId = 1;

Player::Player() {
    id = nextId++;
}

int Player::getPlayerId() {
    return this->id;
}