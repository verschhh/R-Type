/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main.hpp
*/

#ifndef _MAIN_HPP_
    #define _MAIN_HPP_

    #include <iostream>

/**
 * @brief Class that give a index to an Entity
 */

class Entity
{
    public:
        /**
         * @brief Construct a new Entity object
         *
         * @param _id Index given to the entity
         */
        explicit Entity(std::size_t _id) : id(_id) {}

        /**
         * @brief Destroy the Entity object
         */
        ~Entity() = default;

        /**
         * @brief Return the id in std::size_t
         *
         * @return std::size_t
         */
        operator std::size_t() const {
            return id;
        }

    private:
        std::size_t id; ///< Entity ID of type std::size_t
};

#endif