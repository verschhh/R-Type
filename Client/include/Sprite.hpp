/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sprite.hpp
*/

#ifndef _SPRITE_HPP_
    #define _SPRITE_HPP_

    #include <SFML/Graphics.hpp>
    #include "Missile.hpp"

class SpriteManager {
    public:

    public:

    SpriteManager() = default;

    bool loadFromFile(std::string file) { return texture.loadFromFile(file); };
    void setTexture() { my_sprite.setTexture(texture); };
    void setScale(float x, float y) {my_sprite.setScale(x, y); };
    void setPosition(float x, float y) { my_sprite.setPosition(x, y); };
    sf::Vector2f getPosition() {return my_sprite.getPosition(); };

    sf::Sprite my_sprite;
    std::vector<Missile> missiles;

    private:

    sf::Texture texture;
};



#endif