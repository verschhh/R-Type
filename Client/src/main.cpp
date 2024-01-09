/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Custom R-Type Implementation
*/

#include "../include/Sound.hpp"
#include "../include/Sprite.hpp"
#include "../include/Input.hpp"
#include <iostream>

void events(SfmlWindow &myWindow) {
    while (myWindow.pollEvent(myWindow.event)) {
        if (myWindow.isClosedEvent(myWindow.event)) {
            myWindow.close();
        }
    }
}

int launch_music(Sound &music) {
    if (!music.loadFromFileMusic("./Client/Assets/Sounds/rick.ogg")) {
        std::cout << "Invalid music file" << std::endl;
        return -1;
    }
    music.setVolumeMusic(10);
    music.musicLoop(true);
    music.playMusic();
    return 0;
}

int load_sprites(Sprite &sprite) {
     if (!sprite.loadFromFile("./Client/Assets/Image/rick.png")) {
        std::cout << "Invalid texture file" << std::endl;
        return -1;
    }
    sprite.setScale(0.5, 0.5);
    sprite.setPosition(0.0, 0.0);
    sprite.setTexture();
    return 0;
}

int main() {
    SfmlWindow myWindow(800, 600, "SFML Encapsulated Window");

    while (myWindow.isOpen()) {
        events(myWindow);
        myWindow.clear();
        myWindow.display();
    }
}