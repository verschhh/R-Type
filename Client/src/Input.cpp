/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Input.cpp
*/

#include "../include/Input.hpp"

float Input::moveLeft(float pos, float speed) {
    return pos - speed;
}

float Input::moveRight(float pos, float speed) {
    return pos + speed;
}

float Input::moveUp(float pos, float speed) {
    return pos - speed;
}

float Input::moveDown(float pos, float speed) {
    return pos + speed;
}