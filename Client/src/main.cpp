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
#include "../include/Enemy.hpp"
#include "../include/Player.hpp"
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
    // create the window
    SfmlWindow myWindow(1920, 1080, "R-Type");

    // create the registry
    Registry registry;
    registry.register_component<CSprite>();
    registry.register_component<Input>();

    // create the sprite
    Enemy enemy(&registry, "./Client/Assets/Image/Felix.png", 3);
    Player player(&registry, "./Client/Assets/Image/rick.png", 3);

    while (myWindow.isOpen()) {
        events(myWindow);
        handleMouvement(&player.cSprite, player.input, &player.sprite);


        myWindow.clear();
        enemy.draw(myWindow.window);
        player.draw(myWindow.window);
        myWindow.display();
    }
}