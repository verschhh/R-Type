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


void events(SfmlWindow &myWindow, std::vector<std::unique_ptr<Enemy>>& enemies, std::unique_ptr<Player>& player) {
    sf::Event event;

    while (myWindow.pollEvent(event)) {
        if (myWindow.isClosedEvent(event)) {
            myWindow.close();
            enemies.clear();
            player.reset();
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
            mySprite->x = my_input.moveRight(mySprite->x, 0.8);
    }
    if (my_input.isQPressed()) {
        mySprite->x = my_input.moveLeft(mySprite->x, 0.8);
    }
    if (my_input.isZPressed()) {
        mySprite->y = my_input.moveUp(mySprite->y, 0.8);
    }
    if (my_input.isSPressed()) {
        mySprite->y = my_input.moveDown(mySprite->y, 0.8);
    }
    sprite->setPosition(mySprite->x, mySprite->y);
}

std::vector<std::unique_ptr<Enemy>> spawnNewWave(Registry &registry) {
    srand(time(NULL));
    int random = rand() % 4;
    std::vector<std::unique_ptr<Enemy>> enemies;
    if (random == 0) {
        for (int i = 0; i < 5; ++i) {
            float x = 1920.0f + (100  * (i + 1));
            float y = 500 + (200 * (i + 1));
            enemies.push_back(std::make_unique<Enemy>(&registry, "./Client/Assets/Image/Felix.png", 1, x, y));
        }
    } else if (random == 1) {
        for (int i = 0; i < 5; ++i) {
            float x = 1920.0f + (100  * (i + 1));
            float y = 0 + (200 * (i + 1));
            enemies.push_back(std::make_unique<Enemy>(&registry, "./Client/Assets/Image/Ben.png", 1, x, y));
        }
    } else {
        for (int i = 0; i < 5; ++i) {
            float x = 1920.0f + (100  * (i + 1));
            float y = 800 + (50 * (i + 1));
            enemies.push_back(std::make_unique<Enemy>(&registry, "./Client/Assets/Image/Kentin.png", 1, x, y));
        }
    }
    return enemies;
}

int main() {
    // create the window
    SfmlWindow myWindow(1920, 1080, "R-Type");

    // create the registry
    Registry registry;
    registry.register_component<CSprite>();
    registry.register_component<Input>();

    // create the sprite
    std::unique_ptr<Player> player(new Player(&registry, "./Client/Assets/Image/rick.png", 3));
    std::vector<std::unique_ptr<Enemy>> enemies;
    enemies = spawnNewWave(registry);

    while (myWindow.isOpen()) {
        events(myWindow, enemies, player);
        if (player) {
            if (player->hp > 0)
                handleMouvement(&player->cSprite, player->input, &player->sprite);
        }
        myWindow.clear();

        for (auto& enemy : enemies) {
            if (enemy) {
                if (enemy->cSprite.x < 0) {
                    std::cout << "Player hp go down" << std::endl;
                    player->hp -= 1;
                    enemy->hp = 0;
                    enemy->cSprite.y = -1000; // Move the enemy out of the screen
                }
                if (enemy->hp > 0) {
                    enemy->draw(myWindow.window);
                    if (player->missile.checkCollision({enemy->hitbox}) == true)
                        enemy->hp -= 1;
                    if (enemy->missile.checkCollision({player->hitbox}) == true)
                        player->hp -= 1;
                }
            }
        }

        if (player->hp > 0)
            player->draw(myWindow.window);

        // Check if all enemies are dead
        bool allEnemiesDead = std::all_of(enemies.begin(), enemies.end(), [](const std::unique_ptr<Enemy>& enemy) { return enemy->hp == 0; });
        if (allEnemiesDead) {
            enemies = spawnNewWave(registry);
        }
        myWindow.display();
    }
}
