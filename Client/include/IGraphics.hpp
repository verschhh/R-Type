/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Window.hpp
*/

#ifndef _WINDOW_HPP_
    #define _WINDOW_HPP_

    #include <SFML/Graphics.hpp>
    #include <map>
    #include "Sprite.hpp"

class SfmlWindow {
    /**
     * @brief Window class
     */

    public:

    public:

    SfmlWindow(int width, int height, const std::string& title) : window(sf::VideoMode(width, height), title) {}

    bool isOpen() { return window.isOpen(); };
    bool pollEvent(sf::Event& event) { return window.pollEvent(event); };
    void close() { window.close(); };
    void clear() { window.clear(); };
    void display() { window.display(); };
    void draw(sf::Sprite sprite) { window.draw(sprite); };
    void drawShape(sf::RectangleShape shape) { window.draw(shape); };
    void drawText(sf::Text text) { window.draw(text); };
    bool isClosedEvent(sf::Event& event) const { return event.type == sf::Event::Closed; };

    sf::Event event;
    sf::RenderWindow window;

    protected:
};

#endif