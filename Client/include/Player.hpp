/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "../include/HitBox.hpp"
    #include "../include/IGraphics.hpp"
    #include "../include/Sprite.hpp"
    #include "../include/Components.hpp"
    #include "../include/Input.hpp"
    #include "../include/Missile.hpp"
    #include "../../Server/include/Entity.hpp"
    #include "../../Server/include/Registry.hpp"

class Player {
    public:
        Player(Registry *registry, std::string asset, int hp);
        ~Player();
        int load_sprites(SpriteManager &sprite, CSprite spriteChara);
        void update(float deltaTime, float x, float y);
        void draw(sf::RenderWindow& window);
        Registry *registry;
        SpriteManager sprite;
        HitBox hitbox;
        CSprite initialCSprite;
        CSprite cSprite;
        Input input;
        Missile missile;
        sf::FloatRect rect;
        int hp;
    protected:
    private:
        Entity entity;
};

#endif /* !PLAYER_HPP_ */
