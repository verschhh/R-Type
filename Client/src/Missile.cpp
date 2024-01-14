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
    /**
     * @brief Missile constructor
     * @param width
     * @param height
     * @param speed
     * @param color
     * @param initialDirection
     * @param ammo
     */
    missiles.resize(ammo);
    for (int i = 0; i < missiles.size(); i++) {
        missiles[i].setSize(sf::Vector2f(width, height));
        missiles[i].setFillColor(color);
        hitboxes.push_back(HitBox(height, width, 0, 0));
    }
}

void Missile::shootAmmo(float x, float y) {
    /**
     * @brief Shoots the missile
     * @param x
     * @param y
     */
    if (currentAmmo < ammo) {
        currentAmmo++;
    } else {
        currentAmmo = 0;
    }
    launch(x, y, missileDirection);
}

void Missile::update(float deltaTime, float x, float y) {
    /**
     * @brief Updates the missile's position
     * @param deltaTime
     * @param x
     * @param y
     */
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
    /**
     * @brief Draws the missile
     * @param window
     */
    for (int i = 0; i < missiles.size(); i++) {
        window.draw(missiles[i]);
        window.draw(hitboxes[i].shape);
    }
}

void Missile::launch(float x, float y, sf::Vector2f direction) {
    /**
     * @brief Launches the missile
     * @param x
     * @param y
     * @param direction
     */
    missiles[currentAmmo].setPosition(x, y);
    missileDirection = direction;
}

int Missile::checkCollision(std::vector<HitBox> hitbox) {
    /**
     * @brief Checks if the missile is colliding with a hitbox
     * @param hitbox
     * @return 1 if it is colliding, -1 if it is not
     */
    for (int i = 0; i < hitboxes.size(); i++) {
        if (hitboxes[i].checkCollision(hitbox) == 1) {
            missiles[i].setPosition(2000, 2000);
            return 1;
        }
    }
    return -1;
}