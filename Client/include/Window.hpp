/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Window.hpp
*/

#ifndef _WINDOW_HPP_
    #define _WINDOW_HPP_

    #include <SFML/Graphics.hpp>

class SfmlWindow {
    public:

    SfmlWindow(int width, int height, const std::string& title) : window(sf::VideoMode(width, height), title) {}

    bool isOpen() { return window.isOpen(); };
    bool pollEvent(sf::Event& event) { return window.pollEvent(event); };
    void close() { window.close(); };
    void clear() { window.clear(); };
    void display() { window.display(); };
    void draw(sf::Sprite sprite) { window.draw(sprite); };
    bool isClosedEvent(sf::Event& event) const { return event.type == sf::Event::Closed; };

    sf::Event event;

    protected:
    sf::RenderWindow window;
};

#endif