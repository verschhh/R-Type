/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Missile.cpp
*/

#include "../include/Missile.hpp"
#include <iostream>

Missile::Missile(float width, float height, float speed, sf::Color color, sf::Vector2f initialDirection, int ammo)
    : launchCooldown(1.0f), missileSpeed(speed), missileDirection(initialDirection), ammo(ammo), currentAmmo(0) {
    missiles.resize(ammo);
    for (int i = 0; i < missiles.size(); i++) {
        missiles[i].setSize(sf::Vector2f(width, height));
        missiles[i].setFillColor(color);
        hitboxes.push_back(HitBox(height, width, 0, 0));
    }
}

void Missile::shootAmmo(float x, float y) {
    if (currentAmmo < ammo) {
        currentAmmo++;
    } else {
        currentAmmo = 0;
    }
    launch(x, y, missileDirection);
}

void Missile::update(float deltaTime, float x, float y) {

    if (cooldown.getElapsedTime().asSeconds() >= launchCooldown) {
        cooldown.restart();
        shootAmmo(x, y);
    }
    for (int i = 0; i < missiles.size(); i++) {
        missiles[i].move(missileDirection * missileSpeed * deltaTime);
        hitboxes[i].update(missiles[i].getPosition().x, missiles[i].getPosition().y);
    }
}

void Missile::draw(sf::RenderWindow& window) {
    for (int i = 0; i < missiles.size(); i++) {
        window.draw(missiles[i]);
        window.draw(hitboxes[i].shape);
    }
}

void Missile::launch(float x, float y, sf::Vector2f direction) {
    missiles[currentAmmo].setPosition(x, y);
    missileDirection = direction;
}

void Missile::checkCollision(std::vector<HitBox> hitbox) {
    for (int i = 0; i < hitboxes.size(); i++) {
        if (hitboxes[i].checkCollision(hitbox) == 1) {
            std::cout << "Collision" << std::endl;
        }
    }
}