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

    bool isZPressed() {return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); };
    bool isSPressed() {return sf::Keyboard::isKeyPressed(sf::Keyboard::S); };
    bool isQPressed() {return sf::Keyboard::isKeyPressed(sf::Keyboard::Q); };
    bool isDPressed() {return sf::Keyboard::isKeyPressed(sf::Keyboard::D); };
};

#endif