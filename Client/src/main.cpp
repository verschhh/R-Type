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

enum class GameState {
    Playing,
    Paused,
    Exit,
};

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
            mySprite->x = my_input.moveRight(mySprite->x, 0.4);
    }
    if (my_input.isQPressed()) {
        mySprite->x = my_input.moveLeft(mySprite->x, 0.4);
    }
    if (my_input.isZPressed()) {
        mySprite->y = my_input.moveUp(mySprite->y, 0.4);
    }
    if (my_input.isSPressed()) {
        mySprite->y = my_input.moveDown(mySprite->y, 0.4);
    }
    sprite->setPosition(mySprite->x, mySprite->y);
}

void move(sf::Sprite *sprite, const sf::Vector2f& velocity) {
    sprite->move(velocity);
}


GameState gameEvents(SfmlWindow &myWindow, GameState gameState, sf::RectangleShape playButton, sf::RectangleShape quitButton) {
    sf::Event event;

    while (myWindow.pollEvent(event)) {
        if (myWindow.isClosedEvent(event)) {
            myWindow.close();
            return GameState::Exit;
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(myWindow.window);
            if (gameState == GameState::Playing) {
                if (playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
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

int game(SfmlWindow &myWindow) {
    Missile missile(40.0f, 20.0f, 200.0f, sf::Color::Red, sf::Vector2f(1.0f, 0.0f));
    Registry registry;
    SpriteManager sprite[4];

    registry.register_component<CSprite>();
    registry.register_component<Input>();
    Entity rick = registry.spawn_entity();

    CSprite initialRick = {0.0, 0.0, 0.5, 0.5, "./Client/Assets/Image/rick.png"};
    CSprite backgound = {0.0, 0.0, 1, 1, "./Client/Assets/Image/star.jpg"};
    CSprite planet = {200.0, 100.0, 0.2, 0.2, "./Client/Assets/Image/planets.png"};
    CSprite paul = {400.0, 1010, 1, 1, "./Client/Assets/Image/paul.png"};
    Input input;

    registry.add_component(rick, std::move(initialRick));
    registry.add_component(rick, std::move(input));

    auto &positionArray = registry.get_components<CSprite>();
    auto &inputArray = registry.get_components<Input>();

    CSprite mySprite = positionArray[rick].value();
    Input my_input = inputArray[rick].value();

    load_sprites(sprite[0], mySprite);
    load_sprites(sprite[1], backgound);
    load_sprites(sprite[2], planet);
    load_sprites(sprite[3], paul);

    sf::Vector2f velocity(-0.2f, 0.0f);
    sf::Vector2f velocity_paul(-0.6f, 0.0f);
    std::srand(static_cast<unsigned>(std::time(nullptr)));


    //Pause Button

    sf::RectangleShape playButton(sf::Vector2f(200, 50));
    playButton.setPosition(300, 200);
    playButton.setFillColor(sf::Color::Green);

    sf::RectangleShape quitButton(sf::Vector2f(200, 50));
    quitButton.setPosition(300, 300);
    quitButton.setFillColor(sf::Color::Red);

    sf::Font font;
    if (!font.loadFromFile("./Client/Assets/Image/Arial.ttf")) {
        std::cerr << "Error loading font\n";
    }

    sf::Text playText("Play", font, 30);
    playText.setPosition(370, 210);

    sf::Text quitText("Quit", font, 30);
    quitText.setPosition(370, 310);

    sf::Text pauseText("Paused", font, 40);
    pauseText.setPosition(350, 100);

    GameState gameState = GameState::Playing;




    while (myWindow.isOpen()) {
        gameState = gameEvents(myWindow, gameState, playButton, quitButton);
        handleMouvement(&mySprite, my_input, &sprite[0]);


        myWindow.clear();
        if (gameState == GameState::Exit) {
            return -1;
        }
        if (gameState == GameState::Playing) {
            move(&sprite[2].my_sprite , velocity);
            move(&sprite[3].my_sprite, velocity_paul);


            if (sprite[2].my_sprite.getPosition().x < -200) {
                sprite[2].setPosition(1920, std::rand() % 1080);
            }
            if (sprite[3].my_sprite.getPosition().x < -200) {
                sprite[3].setPosition(1920, 1010);
            }

            missile.update(0.016f, mySprite.x, mySprite.y);
            myWindow.draw(sprite[1].my_sprite);
            myWindow.draw(sprite[2].my_sprite);
            myWindow.draw(sprite[3].my_sprite);
            myWindow.drawShape(playButton);
            myWindow.drawText(playText);
            myWindow.draw(sprite[0].my_sprite);
            myWindow.drawShape(missile.shape);
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
    playButton.setPosition(300, 200);
    playButton.setFillColor(sf::Color::Green);

    sf::RectangleShape quitButton(sf::Vector2f(200, 50));
    quitButton.setPosition(300, 300);
    quitButton.setFillColor(sf::Color::Red);

    sf::Font font;
    if (!font.loadFromFile("./Client/Assets/Image/Arial.ttf")) {
        std::cerr << "Error loading font\n";
    }

    sf::Text playText("Play", font, 30);
    playText.setPosition(370, 210);

    sf::Text quitText("Quit", font, 30);
    quitText.setPosition(370, 310);

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