/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** HitBox
*/

#ifndef HITBOX_HPP_
    #define HITBOX_HPP_

    #include <SFML/Graphics.hpp>

    class HitBox {
        /**
         * @brief HitBox class
         * 
         * This class is used to handle the hitboxes
         * 
         * @param height : the height of the hitbox
         * @param width : the width of the hitbox
         * @param x : the x position of the hitbox
         * @param y : the y position of the hitbox
         * 
         * @return nothing
         */
        public:
                HitBox(float height, float width, float x, float y);
                void update(float deltaTime, float x, float y);
                void draw(sf::RenderWindow& window);
                int checkCollision(std::vector<HitBox> hitbox);
                void update(float x, float y);
                sf::RectangleShape shape;
                float height;
                float width;
                float x;
                float y;
                ~HitBox();

            protected:
        private:
    };

#endif /* !HITBOX_HPP_ */
