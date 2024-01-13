/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#include "../include/Enemy.hpp"

Enemy::Enemy(Registry *registry, std::string asset, int hp) : hitbox(0, 0 , 0 , 0), entity(registry->spawn_entity()), missile(40.0f, 20.0f, 200.0f, sf::Color::Red, sf::Vector2f(-1.0f, 0.0f), 3) {
    this->registry = registry;
    initialCSprite = {500, 500, 0.5, 0.5, asset};
    registry->add_component(entity, std::move(initialCSprite));
    auto &positionArray = registry->get_components<CSprite>();
    this->cSprite = positionArray[entity].value();
    load_sprites(this->sprite, this->cSprite);
    rect = sprite.my_sprite.getGlobalBounds();
    hitbox = HitBox(rect.height, rect.width, cSprite.x, cSprite.y);
    this->hp = hp;
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
    missile.update(0.016f, x, y);
}

void Enemy::draw(sf::RenderWindow& window) {
    update(0, cSprite.x, cSprite.y);
    window.draw(sprite.my_sprite);
    window.draw(hitbox.shape);
    missile.draw(window);
}

Enemy::~Enemy()
{
}