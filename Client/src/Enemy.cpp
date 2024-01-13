/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#include "../include/Enemy.hpp"

Enemy::Enemy(Registry *registry) : hitboxe(0, 0 , 0 , 0), entitie(registry->spawn_entity()) {
    std::cout << "registry" << std::endl;
    this->registry = registry;
    std::cout << "spawn entity" << std::endl;
    // this->entitie = registry->spawn_entity();
    std::cout << "initialCSprite" << std::endl;
    initialCSprite = {0.0, 0.0, 0.5, 0.5, "./Client/Assets/Image/Felix.png"};
    std::cout << "add component" << std::endl;
    registry->add_component(entitie, std::move(initialCSprite));
    std::cout << "positionArray" << std::endl;
    auto &positionArray = registry->get_components<CSprite>();
    std::cout << "load cSprite" << std::endl;
    this->cSprite = positionArray[entitie].value();
    std::cout << "load sprites" << std::endl;
    load_sprites(this->sprite, this->cSprite);
}

int Enemy::load_sprites(SpriteManager &sprite, CSprite spriteChara) {
    if (!sprite.loadFromFile(spriteChara.file)) {
        std::cout << "Invalid texture file" << std::endl;
        return -1;
    }
    sprite.setScale(spriteChara.scaleX, spriteChara.scaleY);
    sprite.setPosition(spriteChara.x, spriteChara.y);
    sprite.setTexture();
    return 0;
}

Enemy::~Enemy()
{
}