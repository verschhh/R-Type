/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Missile.hpp
*/

#ifndef _MISSILE_HPP_
    #define _MISSILE_HPP_

    #include <SFML/Graphics.hpp>
    #include "HitBox.hpp"

    class Missile {
    public:
        Missile(float width, float height, float speed, sf::Color color, sf::Vector2f initialDirection, int ammo);
        void checkCollision(std::vector<HitBox> hitbox);
        void update(float deltaTime, float x, float y);
        void draw(sf::RenderWindow& window);
        void shootAmmo(float x, float y);
        void launch(float x, float y, sf::Vector2f direction);
        sf::RectangleShape shape;
        std::vector<sf::RectangleShape> missiles;
        std::vector <HitBox> hitboxes;

    private:
        int ammo;
        int currentAmmo;
        sf::Clock cooldown;
        float launchCooldown;
        float missileSpeed;
        sf::Vector2f missileDirection;
};



#endif