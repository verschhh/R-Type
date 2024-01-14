/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** playerData.hpp
*/

#ifndef _PLAYERDATA_HPP_
    #define _PLAYERDATA_HPP_

class Player {
    public:

    Player();
    ~Player() = default;

    int getPlayerId();

    private:

    int id;
    static int nextId;
};

#endif