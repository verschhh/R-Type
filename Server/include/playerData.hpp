/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** playerData.hpp
*/

#ifndef _PLAYERDATA_HPP_
    #define _PLAYERDATA_HPP_

/**
 * @brief Class containing information to manage differents Client at the same time
 *
 */
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