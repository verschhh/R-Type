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
    Missile missile(40.0f, 20.0f, 200.0f, sf::Color::Red, sf::Vector2f(1.0f, 0.0f));
    Registry registry;
    SpriteManager sprite;

    registry.register_component<CSprite>();
    registry.register_component<Input>();
    Entity rick = registry.spawn_entity();

    CSprite initialRick = {0.0, 0.0, 0.5, 0.5, "./Client/Assets/Image/rick.png"};
    Input input;

    registry.add_component(rick, std::move(initialRick));
    registry.add_component(rick, std::move(input));

    auto &positionArray = registry.get_components<CSprite>();
    auto &inputArray = registry.get_components<Input>();

    CSprite mySprite = positionArray[rick].value();
    Input my_input = inputArray[rick].value();

    load_sprites(sprite, mySprite);


    while (myWindow.isOpen()) {
        events(myWindow);
        handleMouvement(&mySprite, my_input, &sprite);


        myWindow.clear();
        missile.update(0.016f, mySprite.x, mySprite.y);
        myWindow.draw(sprite.my_sprite);
        myWindow.drawShape(missile.shape);
        myWindow.display();
    }
}