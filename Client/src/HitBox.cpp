/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** HitBox
*/

#include "../include/HitBox.hpp"
#include <iostream>

HitBox::HitBox(float height, float width, float x, float y)
{
    std::cout << "In" << std::endl;
    this->height = height;
    this->width = width;
    this->x = x;
    this->y = y;
    this->shape.setSize(sf::Vector2f(this->width, this->height));
    this->shape.setPosition(sf::Vector2f(this->x, this->y));
    this->shape.setFillColor(sf::Color::Transparent);
    this->shape.setOutlineThickness(1);
    this->shape.setOutlineColor(sf::Color::Yellow);
    std::cout << "HitBox created" << std::endl;
}

void HitBox::update(float x, float y)
{
    this->x = x;
    this->y = y;
    this->shape.setPosition(sf::Vector2f(this->x, this->y));
}

int HitBox::checkCollision(std::vector<HitBox> hitbox)
{
    for (int i = 0; i < hitbox.size(); i++) {
        if (this->shape.getGlobalBounds().intersects(hitbox[i].shape.getGlobalBounds())) {
            return 1;
        }
    }
    return -1;
}

HitBox::~HitBox()
{
}
