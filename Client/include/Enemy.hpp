/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** Enemy
*/

#ifndef ENEMY_HPP_
    #define ENEMY_HPP_

    #include "../include/HitBox.hpp"
    #include "../include/IGraphics.hpp"
    #include "../include/Sprite.hpp"
    #include "../include/Components.hpp"
    #include "../../Server/include/Entity.hpp"
    #include "../../Server/include/Registry.hpp"

class Enemy {
    public:
        Enemy(Registry *registry);
        ~Enemy();
        int load_sprites(SpriteManager &sprite, CSprite spriteChara);
        void update(float deltaTime, float x, float y);
        void draw(sf::RenderWindow& window);
        Registry *registry;
        SpriteManager sprite;
        HitBox hitbox;
        CSprite initialCSprite;
        CSprite cSprite;
        sf::FloatRect rect;
    protected:
    private:
        Entity entity;
};

#endif /* !ENEMY_HPP_ */
