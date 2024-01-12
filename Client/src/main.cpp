/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Custom R-Type Implementation
*/

#include "../include/IGraphics.hpp"
#include "../include/Sprite.hpp"
#include "../include/Components.hpp"
#include "../../Server/include/Registry.hpp"
#include "../include/Sound.hpp"
#include "../include/Input.hpp"
#include "../include/Missile.hpp"
#include "../include/HitBox.hpp"
#include <iostream>

void events(SfmlWindow &myWindow) {
    sf::Event event;

    while (myWindow.pollEvent(event)) {
        if (myWindow.isClosedEvent(event)) {
            myWindow.close();
        }
    }
}

int launch_music(Sound &music, std::string file) {
    if (!music.loadFromFileMusic(file)) {
        std::cout << "Invalid music file" << std::endl;
        return -1;
    }
    music.setVolumeMusic(10);
    music.musicLoop(true);
    music.playMusic();
    return 0;
}

int load_sprites(SpriteManager &sprite, CSprite spriteChara) {
     if (!sprite.loadFromFile(spriteChara.file)) {
        std::cout << "Invalid texture file" << std::endl;
        return -1;
    }
    sprite.setScale(spriteChara.scaleX, spriteChara.scaleY);
    sprite.setPosition(spriteChara.x, spriteChara.y);
    sprite.setTexture();
    return 0;
}

void handleMouvement(CSprite *mySprite, Input my_input, SpriteManager *sprite) {
    if (my_input.isDPressed()) {
            mySprite->x = my_input.moveRight(mySprite->x, 0.2);
    }
    if (my_input.isQPressed()) {
        mySprite->x = my_input.moveLeft(mySprite->x, 0.2);
    }
    if (my_input.isZPressed()) {
        mySprite->y = my_input.moveUp(mySprite->y, 0.2);
    }
    if (my_input.isSPressed()) {
        mySprite->y = my_input.moveDown(mySprite->y, 0.2);
    }
    sprite->setPosition(mySprite->x, mySprite->y);
}

int main() {
    SfmlWindow myWindow(1920, 1080, "R-Type");
    Missile missile(40.0f, 20.0f, 200.0f, sf::Color::Red, sf::Vector2f(1.0f, 0.0f), 3);
    Registry registry;


    // create a sprite manager
    SpriteManager sprite;
    SpriteManager sprite2;

    registry.register_component<CSprite>();
    registry.register_component<Input>();

    // Create entities
    Entity rick = registry.spawn_entity();
    Entity felix = registry.spawn_entity();

    // Add components to entities
    CSprite initialRick = {0.0, 0.0, 0.5, 0.5, "./Client/Assets/Image/rick.png"};
    CSprite initialFelix = {500, 500, 0.5, 0.5, "./Client/Assets/Image/Felix.png"};
    Input input;

    // Add components to registry
    registry.add_component(rick, std::move(initialRick));
    registry.add_component(rick, std::move(input));
    registry.add_component(felix, std::move(initialFelix));

    auto &positionArray = registry.get_components<CSprite>();
    auto &inputArray = registry.get_components<Input>();

    CSprite mySprite = positionArray[rick].value();
    CSprite mySprite2 = positionArray[felix].value();
    Input my_input = inputArray[rick].value();

    // create the hitbox
    HitBox RickHitBox(50, 50, mySprite.x, mySprite.y);
    HitBox FelixHitBox(110, 110, mySprite2.x, mySprite2.y);

    load_sprites(sprite, mySprite);
    load_sprites(sprite2, mySprite2);


    while (myWindow.isOpen()) {
        events(myWindow);
        handleMouvement(&mySprite, my_input, &sprite);


        myWindow.clear();
        missile.update(0.016f, mySprite.x, mySprite.y);
        RickHitBox.update(mySprite.x, mySprite.y);
        FelixHitBox.update(mySprite2.x, mySprite2.y);
        myWindow.draw(sprite.my_sprite);
        myWindow.draw(sprite2.my_sprite);
        myWindow.drawShape(RickHitBox.shape);
        myWindow.drawShape(FelixHitBox.shape);
        missile.draw(myWindow.window);
        missile.checkCollision({FelixHitBox});
        if (RickHitBox.checkCollision({FelixHitBox}) == 1) {
            std::cout << "Collision" << std::endl;
        }
        myWindow.display();
    }
}