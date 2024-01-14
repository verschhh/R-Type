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
    /** Event
     * @brief Handle the events
     * 
     * @param event : the event
     * @param myWindow : the window
     * @param enemies : the enemies
     * @param player : the player
     * 
     * @return void
    */
    while (myWindow.pollEvent(event)) {
        if (myWindow.isClosedEvent(event)) {
            myWindow.close();
            enemies.clear();
            player.reset();
        }
    }
}

int launch_music(Sound &music, std::string file) {
    /** launch_music
     * @brief Launch the music
     * 
     * @param music : the music
     * @param file : the path to the music
     * 
     * @return 0 if it is a success, -1 if it is not
    */

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
    /** load_sprites
     * @brief Loads the sprite
     * 
     * @param sprite : the sprite
     * @param spriteChara : the spriteChara
     * 
     * @return 0 if it is a success, -1 if it is not
    */

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
    /** handleMouvement
     * @brief Handle the mouvement of the player
     * 
     * @param mySprite : the sprite of the player
     * @param my_input : the input of the player
     * @param sprite : the sprite of the player
     * 
     * @return void
    */
    if (my_input.isDPressed()) {
        if (mySprite->x < 1850)
            mySprite->x = my_input.moveRight(mySprite->x, 0.8);
    }
    if (my_input.isQPressed()) {
        if (mySprite->x > 0)
            mySprite->x = my_input.moveLeft(mySprite->x, 0.8);
    }
    if (my_input.isZPressed()) {
        if (mySprite->y > 0)
            mySprite->y = my_input.moveUp(mySprite->y, 0.8);
    }
    if (my_input.isSPressed()) {
        if (mySprite->y < 950)
            mySprite->y = my_input.moveDown(mySprite->y, 0.8);
    }
    sprite->setPosition(mySprite->x, mySprite->y);
}

std::vector<std::unique_ptr<Enemy>> spawnNewWave(Registry &registry) {
    /** spawnNewWave
     * @brief Spawn a new wave of enemies
     * 
     * @param registry : the registry
     * 
     * @return enemies : the enemies
    */
    std::vector<std::unique_ptr<Enemy>> enemies;
    srand(time(NULL));
    for (int i = 0; i < 5; ++i) {
        int random = rand() % 3;
        float x = 1920.0f;
        float y = 0 + (200 * (random  + i));
        if (random == 0)
            enemies.push_back(std::make_unique<Enemy>(&registry, "./Client/Assets/Image/Felix.png", 1, x, y, 0));
        else if (random == 1)
            enemies.push_back(std::make_unique<Enemy>(&registry, "./Client/Assets/Image/Ben.png", 1, x, y, 1));
        else
            enemies.push_back(std::make_unique<Enemy>(&registry, "./Client/Assets/Image/Kentin.png", 1, x, y, 2));
    }
    return enemies;
}

int main() {
    /** main
     * @brief Main function
     * 
     * a function that launch the game and handle the events and the mouvement of the player and the enemies and the music and the wave of enemies and the collision between the player and the enemies and the collision between the player and the enemies' missiles and the collision between the enemies and the player's missiles 
     * 
     * @return 0 if it is a success, -1 if it is not
    */

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
