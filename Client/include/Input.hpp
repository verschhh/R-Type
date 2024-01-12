/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Input.hpp
*/

#ifndef _INPUT_HPP_
    #define _INPUT_HPP_

    #include <SFML/Window/Keyboard.hpp>

class Input {
    public:

    Input() = default;
    ~Input() = default;

    bool isZPressed() {return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); };
    bool isSPressed() {return sf::Keyboard::isKeyPressed(sf::Keyboard::S); };
    bool isQPressed() {return sf::Keyboard::isKeyPressed(sf::Keyboard::Q); };
    bool isDPressed() {return sf::Keyboard::isKeyPressed(sf::Keyboard::D); };

    float moveRight(float pos, float speed);
    float moveLeft(float pos, float speed);
    float moveUp(float pos, float speed);
    float moveDown(float pos, float speed);
};

#endif