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
    /**
     * @brief Input class
     * 
     * This class is used to handle the inputs
     * 
     * @param isZPressed : is the Z key pressed
     * @param isSPressed : is the S key pressed
     * @param isQPressed : is the Q key pressed
     * @param isDPressed : is the D key pressed
     * @param moveRight : moves the player to the right
     * @param moveLeft : moves the player to the left
     * @param moveUp : moves the player to the top
     * @param moveDown : moves the player to the bottom
     * 
     * @return nothing
     */
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