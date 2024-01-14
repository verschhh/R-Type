/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#include "../include/Enemy.hpp"

Enemy::Enemy(Registry *registry, std::string asset, int hp, float x, float y, int color) : hitbox(0, 0 , 0 , 0), entity(registry->spawn_entity()), missile(40.0f, 20.0f, 200.0f, sf::Color::Red, sf::Vector2f(-1.0f, 0.0f), 3) {
    this->registry = registry;
    initialCSprite = {x, y, 0.5, 0.5, asset};
    registry->add_component(entity, std::move(initialCSprite));
    auto &positionArray = registry->get_components<CSprite>();
    this->cSprite = positionArray[entity].value();
    load_sprites(this->sprite, this->cSprite);
    rect = sprite.my_sprite.getGlobalBounds();
    hitbox = HitBox(rect.height, rect.width, cSprite.x, cSprite.y);
    this->hp = hp;
    this->x = x;
    this->y = y;
    launchCooldown = 0.2f;
    if (color == 0)
        missile = Missile(40.0f, 20.0f, 200.0f, sf::Color::Red, sf::Vector2f(-1.0f, 0.0f), 3);
    else if (color == 1)
        missile = Missile(40.0f, 80.0f, 200.0f, sf::Color::Blue, sf::Vector2f(-1.0f, 0.0f), 2);
    else
        missile = Missile(60.0f, 60.0f, 100.0f, sf::Color::Green, sf::Vector2f(-1.0f, 0.0f), 2);
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
    if (cooldown.getElapsedTime().asSeconds() >= launchCooldown) {
        this->x -= 10;
        if (this->y < 50)
            this->y = 1000;
        else
            this->y -= 5;
        cooldown.restart();
    }
    hitbox.update(x, y);
    sprite.setPosition(x, y);
    if (cSprite.x < 1920 && cSprite.x > 0 && cSprite.y < 1080 && cSprite.y > 0)
        missile.update(0.016f, x, y);
}

void Enemy::draw(sf::RenderWindow& window) {
    cSprite.x = this->x;
    cSprite.y = this->y;
    update(0, cSprite.x, cSprite.y);
    window.draw(sprite.my_sprite);
    window.draw(hitbox.shape);
    if (cSprite.x < 1920 && cSprite.x > 0 && cSprite.y < 1080 && cSprite.y > 0)
        missile.draw(window);
}
