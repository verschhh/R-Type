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
        Enemy(Registry registry);
        ~Enemy();
        int load_sprites(SpriteManager &sprite, CSprite spriteChara);
        Registry registry;
        SpriteManager sprite;
        HitBox hitboxe;
        Entity entitie;
        CSprite initialCSprite;
        CSprite cSprite;
    protected:
    private:
};

#endif /* !ENEMY_HPP_ */
