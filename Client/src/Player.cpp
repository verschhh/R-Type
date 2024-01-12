/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Player
*/

#include "../include/Player.hpp"

Player::Player(float height, float width, float x, float y, std::string filename, auto &entity)
{
    this->height = height;
    this->width = width;
    this->x = x;
    this->y = y;
    this->rick = entity;
    this->initialRick = {height, width, x, y, filename};

}
