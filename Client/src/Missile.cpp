/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Missile.cpp
*/

#include "../include/Missile.hpp"

Missile::Missile(float width, float height, float speed, sf::Color color, sf::Vector2f initialDirection)
    : launchCooldown(1.0f), missileSpeed(speed), missileDirection(initialDirection) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(color);
}

void Missile::update(float deltaTime, float x, float y) {
    if (cooldown.getElapsedTime().asSeconds() >= launchCooldown) {
        launch(x, y, missileDirection);
        cooldown.restart();
    }
    shape.move(missileDirection * missileSpeed * deltaTime);
}

void Missile::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Missile::launch(float x, float y, sf::Vector2f direction) {
    shape.setPosition(x, y);
    missileDirection = direction;
}