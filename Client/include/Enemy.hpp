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
    #include "../include/Missile.hpp"
    #include "../../Server/include/Entity.hpp"
    #include "../../Server/include/Registry.hpp"

class Enemy {
    public:
        Enemy(Registry *registry, std::string asset, int hp, float x, float y);
        ~Enemy() = default;
        int load_sprites(SpriteManager &sprite, CSprite spriteChara);
        void update(float deltaTime, float x, float y);
        void draw(sf::RenderWindow& window);
        Registry *registry;
        SpriteManager sprite;
        HitBox hitbox;
        CSprite initialCSprite;
        CSprite cSprite;
        Missile missile;
        sf::FloatRect rect;
        int hp;
        int x;
        int y;
    protected:
    private:
        Entity entity;
};

#endif /* !ENEMY_HPP_ */
