/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Components.hpp
*/

#ifndef _COMPONENTS_HPP_
    #define _COMPONENTS_HPP_

    #include <iostream>

    struct Position
    {
        /** @brief Position struct
         * 
         *  This struct is used to store the position of an entity
         * 
         *  @param x : the x position
         *  @param y : the y position
        */
        float x, y;
    };

    struct CSprite
    {
        /** @brief CSprite struct
         * 
         *  This struct is used to store the sprite of an entity
         * 
         *  @param file : the path to the sprite
         *  @param x : the x position
         *  @param y : the y position
         *  @param scaleX : the x scale
         *  @param scaleY : the y scale
        */
        float x, y;
        float scaleX, scaleY;
        std::string file;
    };

#endif