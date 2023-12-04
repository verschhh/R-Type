/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main.hpp
*/

#ifndef _MAIN_HPP_
    #define _MAIN_HPP_

    #include <iostream>

    class Entity
    {
        public:
            explicit Entity(size_t value) : data(value) {}

            operator size_t() const {
                return data;
            }

        private:
            size_t data;
    };

#endif