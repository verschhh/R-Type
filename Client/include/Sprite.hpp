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
    /**
     * @brief SpriteManager class
     * 
     * This class is used to handle the sprites
     * 
     * @param my_sprite : the sprite
     * @param texture : the texture
     * @param missiles : the missiles
     * 
     * @return nothing
     */
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