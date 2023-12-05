/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main.cpp
*/

/** @file main.cpp
*/

/**
 * @brief Adds two integers.
 *
 * This function takes two integers as input and returns their sum.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return The sum of the two integers.
 */

#include <SFML/Graphics.hpp>

int test(int a, int b) {
    return a + b;
}

/**
 * @brief The main function.
 *
 * This is the main function of the program. It calls the test function with
 * the values 2 and 4, and returns the result.
 *
 * @param ac The number of command-line arguments.
 * @param av The array of command-line arguments.
 * @return The result of the test function.
 */

int main(int ac, char **av) {
    int result = test(2, 4);
    //make a SMFL window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    //make a SFML circle
    sf::CircleShape shape(100.f);
    //set the shape color to green
    shape.setFillColor(sf::Color::Green);
    //run the program as long as the window is open
    while (window.isOpen()) {
        //check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            //close the window if a key is pressed or if the close button is pressed
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
                window.close();
        }
        //clear the window with black color
        window.clear(sf::Color::Black);
        //draw everything here
        //window.draw(...);
        window.draw(shape);
        //end the current frame
        window.display();
    }

    return result;
}