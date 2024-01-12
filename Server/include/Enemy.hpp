/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

    #include <string>
    #include <iostream>
    #include <vector>
    #include <fstream>
    #include <sstream>

    struct Weapon {
        std::string name;
        int damage;
        float cooldown;
    };

    struct Enemy {
        std::string name;
        int health;
        std::pair<int, int> movement;
        float delay;
        Weapon weapon;
    };

    std::vector<Enemy> parseEnemies(std::string filename);
    int getSizeOfEnemies(std::vector<Enemy> enemies);
    int getEnemyIndex(std::vector<Enemy> enemies, std::string name);
    Enemy getEnemy(std::vector<Enemy> enemies, std::string name);
    std::string getEnemyName(std::vector<Enemy> enemies, std::string name);
    int getEnemyHealth(std::vector<Enemy> enemies, std::string name);
    int getEnemyDamage(std::vector<Enemy> enemies, std::string name);
    float getEnemyCooldown(std::vector<Enemy> enemies, std::string name);
    std::pair<int, int> getEnemyMovement(std::vector<Enemy> enemies, std::string name);
    float getEnemyDelay(std::vector<Enemy> enemies, std::string name);


#endif /* !ENEMY_HPP_ */
