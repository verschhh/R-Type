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
    /**
     * @brief Enemy class
     * 
     * This class is used to create an enemy
     * 
     * @param hitbox : the hitbox of the enemy
     * @param entity : the entity of the enemy
     * @param missile : the missile of the enemy
     * @param initialCSprite : the initial sprite of the enemy
     * @param cSprite : the current sprite of the enemy
     * @param sprite : the sprite of the enemy
     * @param rect : the rect of the enemy
     * @param cooldown : the cooldown of the enemy
     * @param launchCooldown : the launch cooldown of the enemy
     * @param x : the x position of the enemy
     * @param y : the y position of the enemy
     * @param hp : the hp of the enemy
     * @param registry : the registry
     * @param asset : the path to the sprite
     * @param hp : the hp of the enemy
     * 
     */
    public:
        Enemy(Registry *registry, std::string asset, int hp, float x, float y, int Color);
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
        sf::Clock cooldown;
        float launchCooldown;
        sf::FloatRect rect;
        int hp;
        int x;
        int y;
    protected:
    private:
        Entity entity;
};

#endif /* !ENEMY_HPP_ */
