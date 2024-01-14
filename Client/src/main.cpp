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

enum class GameState {
    Playing,
    Paused,
    Exit,
};

// int launch_music(Sound &music, std::string file) {
//     /** launch_music
//      * @brief Launch the music
//      *
//      * @param music : the music
//      * @param file : the path to the music
//      *
//      * @return 0 if it is a success, -1 if it is not
//     */

//     if (!music.loadFromFileMusic(file)) {
//         std::cout << "Invalid music file" << std::endl;
//         return -1;
//     }
//     music.setVolumeMusic(10);
//     music.musicLoop(true);
//     music.playMusic();
//     return 0;
// }

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

void move(sf::Sprite *sprite, const sf::Vector2f& velocity) {
    sprite->move(velocity);
}


GameState gameEvents(SfmlWindow &myWindow, GameState gameState, sf::RectangleShape playButton, sf::RectangleShape quitButton,
    sf::RectangleShape stopButton) {
    sf::Event event;

    while (myWindow.pollEvent(event)) {
        if (myWindow.isClosedEvent(event)) {
            myWindow.close();
            return GameState::Exit;
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(myWindow.window);
            if (gameState == GameState::Playing) {
                if (stopButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    return GameState::Paused;
                }
            } else if (gameState == GameState::Paused) {
                if (playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    return GameState::Playing;
                }
                else if (quitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    myWindow.close();
                    return GameState::Exit;
                }
            }
        }
    }
    return gameState;
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

int game(SfmlWindow &myWindow) {
    Registry registry;
    SpriteManager sprite[4];
    Entity rick = registry.spawn_entity();
    registry.register_component<CSprite>();
    registry.register_component<Input>();

    // create the player and the enemies
    std::vector<std::unique_ptr<Enemy>> enemies;
    enemies = spawnNewWave(registry);
    std::unique_ptr<Player> player(new Player(&registry, "./Client/Assets/Image/rick.png", 3));

    // load the sprites
    CSprite backgound = {0.0, 0.0, 1, 1, "./Client/Assets/Image/star.jpg"};
    CSprite planet = {200.0, 100.0, 0.2, 0.2, "./Client/Assets/Image/planets.png"};
    CSprite paul = {400.0, 1010, 1, 1, "./Client/Assets/Image/paul.png"};
    CSprite littlePlanet{600.0, 754, 0.1, 0.1, "./Client/Assets/Image/planets.png"};

    load_sprites(sprite[0], backgound);
    load_sprites(sprite[1], planet);
    load_sprites(sprite[2], paul);
    load_sprites(sprite[3], littlePlanet);

    sf::Vector2f velocity(-0.2f, 0.0f);
    sf::Vector2f velocity_paul(-0.6f, 0.0f);
    sf::Vector2f velocity_littlePlanet(-0.1f, 0.0f);
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    sf::RectangleShape playButton(sf::Vector2f(200, 50));
    playButton.setPosition(800, 400);
    playButton.setFillColor(sf::Color::Green);

    sf::RectangleShape quitButton(sf::Vector2f(200, 50));
    quitButton.setPosition(800, 600);
    quitButton.setFillColor(sf::Color::Red);

    sf::RectangleShape stopButton(sf::Vector2f(50, 50));
    stopButton.setPosition(50, 50);
    stopButton.setFillColor(sf::Color::Black);

    sf::Font font;
    if (!font.loadFromFile("./Client/Assets/Image/Arial.ttf")) {
        std::cerr << "Error loading font\n";
    }

    sf::Text playText("Play", font, 30);
    playText.setPosition(870, 410);

    sf::Text quitText("Quit", font, 30);
    quitText.setPosition(870, 610);

    sf::Text pauseText("Paused", font, 40);
    pauseText.setPosition(840, 210);

    sf::Text stopText(" ||", font, 30);
    stopText.setPosition(50, 50);

    GameState gameState = GameState::Playing;

    while (myWindow.isOpen()) {
        gameState = gameEvents(myWindow, gameState, playButton, quitButton, stopButton);
         if (player) {
             handleMouvement(&player->cSprite, player->input, &player->sprite);
         }
        myWindow.clear();
        if (gameState == GameState::Exit) {
            return -1;
        }
        if (gameState == GameState::Playing) {
            move(&sprite[1].my_sprite , velocity);
            move(&sprite[2].my_sprite, velocity_paul);
            move(&sprite[3].my_sprite, velocity_littlePlanet);


            if (sprite[1].my_sprite.getPosition().x < -200) {
                sprite[1].setPosition(1920, std::rand() % 1080);
            }
            if (sprite[2].my_sprite.getPosition().x < -200) {
                sprite[2].setPosition(1920, 1010);
            }
            if (sprite[3].my_sprite.getPosition().x < -200) {
                sprite[3].setPosition(1920, std::rand() % 1080);
            }

            myWindow.draw(sprite[0].my_sprite);
            myWindow.draw(sprite[1].my_sprite);
            myWindow.draw(sprite[2].my_sprite);
            myWindow.draw(sprite[3].my_sprite);
            for (auto& enemy : enemies) {
                if (enemy) {
                    if (enemy->cSprite.x < 0) {
                        std::cout << "Player hp go down" << std::endl;
                        player->hp -= 1;
                        enemy->hp = 0;
                        enemy->cSprite.y = -1000;
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
            if (player) {
                if (player->hp > 0) {
                    player->draw(myWindow.window);
                }
            }
            myWindow.drawShape(stopButton);
            myWindow.drawText(stopText);
        } else if (gameState == GameState::Paused) {
            myWindow.drawText(pauseText);
            myWindow.drawShape(playButton);
            myWindow.drawShape(quitButton);
            myWindow.drawText(playText);
            myWindow.drawText(quitText);
        }
        myWindow.display();
    }
    return 0;
}



int events(SfmlWindow &myWindow, sf::RectangleShape playButton, sf::RectangleShape quitButton) {
    sf::Event event;

    while (myWindow.pollEvent(event)) {
        if (myWindow.isClosedEvent(event)) {
            myWindow.close();
            return -1;
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(myWindow.window);
            if (playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                return (game(myWindow));
            } else if (quitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                myWindow.close();
                return -1;
            }
        }
    }
    return 0;
}

int mainLoop() {
    SfmlWindow myWindow(1920, 1080, "R-Type");

    sf::RectangleShape playButton(sf::Vector2f(200, 50));
    playButton.setPosition(800, 400);
    playButton.setFillColor(sf::Color::Green);

    sf::RectangleShape quitButton(sf::Vector2f(200, 50));
    quitButton.setPosition(800, 600);
    quitButton.setFillColor(sf::Color::Red);

    sf::Font font;
    if (!font.loadFromFile("./Client/Assets/Image/Arial.ttf")) {
        std::cerr << "Error loading font\n";
    }

    sf::Text playText("Play", font, 30);
    playText.setPosition(870, 410);

    sf::Text quitText("Quit", font, 30);
    quitText.setPosition(870, 610);

    while (myWindow.isOpen()) {
        sf::Event event;
        if (events(myWindow, playButton, quitButton) == -1) {
            return -1;
        }
        myWindow.clear();
        myWindow.drawShape(playButton);
        myWindow.drawShape(quitButton);
        myWindow.drawText(playText);
        myWindow.drawText(quitText);
        myWindow.display();
    }
    return 0;
}