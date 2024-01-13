/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#include "../include/Enemy.hpp"

Enemy::Enemy(Registry *registry) : hitbox(0, 0 , 0 , 0), entity(registry->spawn_entity()) {
    this->registry = registry;
    initialCSprite = {0.0, 0.0, 0.5, 0.5, "./Client/Assets/Image/Felix.png"};
    registry->add_component(entity, std::move(initialCSprite));
    auto &positionArray = registry->get_components<CSprite>();
    this->cSprite = positionArray[entity].value();
    load_sprites(this->sprite, this->cSprite);
    rect = sprite.my_sprite.getGlobalBounds();
    hitbox = HitBox(rect.height, rect.width, cSprite.x, cSprite.y);
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

void Enemy::update(float deltaTime, float x, float y) {
    hitbox.update(x, y);
    sprite.setPosition(x, y);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite.my_sprite);
    window.draw(hitbox.shape);
}

Enemy::~Enemy()
{
}