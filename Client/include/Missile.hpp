/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Missile.hpp
*/

#ifndef _MISSILE_HPP_
    #define _MISSILE_HPP_

    #include <SFML/Graphics.hpp>

    class Missile {
    public:
        Missile(float width, float height, float speed, sf::Color color, sf::Vector2f initialDirection);

        void update(float deltaTime, float x, float y);
        void draw(sf::RenderWindow& window);

        void launch(float x, float y, sf::Vector2f direction);
        sf::RectangleShape shape;

    private:
        sf::Clock cooldown;
        float launchCooldown;
        float missileSpeed;
        sf::Vector2f missileDirection;
};



#endif