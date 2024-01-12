/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#include "../include/Enemy.hpp"

std::vector<Enemy> parseEnemies(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<Enemy> enemies;
    Enemy currentEnemy;
    Weapon currentWeapon;
    bool isWeapon = false;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        iss >> key;
        std::cout << isWeapon << std::endl;
        if (key == "enemy") {
            continue;
        } else if (key == "{") {
            continue;
        } else if (key == "},") {
            if (isWeapon) {
                currentEnemy.weapon = currentWeapon;
                std::cout << "weapon name: " << currentEnemy.weapon.name << "\nweapon stat: " << currentEnemy.weapon.damage << " " << currentEnemy.weapon.cooldown << std::endl;
                isWeapon = false;
                continue;
            }
        } else if (key == "}") {
            if (!isWeapon) { 
                std::cout << "pushed back" << std::endl;
                enemies.push_back(currentEnemy);
                continue;
            }
        } else if (key == "weapon=") {
            isWeapon = true;
            iss >> currentWeapon.name;
            std::cout << currentWeapon.name << std::endl;
            continue;
        }

        std::string value;
        std::string equalsSign;

        if (isWeapon) {
            if (key == "damage=") {
                iss >> value;
                std::cout << value << std::endl;
                currentWeapon.damage = std::stoi(value);
            } else if (key == "cooldown=") {
                iss >> value;
                std::cout << value << std::endl;
                currentWeapon.cooldown = std::stof(value);
            }
        } else {
            if (key == "name=") {
                iss >> value;
                currentEnemy.name = value;
            } else if (key == "health=") {
                iss >> value;
                currentEnemy.health = std::stoi(value);
            } else if (key == "movement=") {
                float x, y;
                iss >> x >> y;
                currentEnemy.movement = {x, y};
            } else if (key == "delay=") {
                iss >> value;
                currentEnemy.delay = std::stof(value);
            }
        }
    }
    return enemies;
}

int getEnemyIndex(std::vector<Enemy> enemies, std::string name) {
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].name == name)
            return i;
    }
    return -1;
}

Enemy getEnemy(std::vector<Enemy> enemies, std::string name) {
    for (auto enemy : enemies) {
        if (enemy.name == name)
            return enemy;
    }
    return Enemy();
}

std::string getEnemyName(std::vector<Enemy> enemies, int index) {
    return enemies[index].name;
}

int getEnemyHealth(std::vector<Enemy> enemies, std::string name) {
    for (auto enemy : enemies) {
        if (enemy.name == name)
            return enemy.health;
    }
    return -1;
}

int getEnemyDamage(std::vector<Enemy> enemies, std::string name) {
    for (auto enemy : enemies) {
        if (enemy.name == name)
            return enemy.weapon.damage;
    }
    return -1;
}

float getEnemyCooldown(std::vector<Enemy> enemies, std::string name) {
    for (auto enemy : enemies) {
        if (enemy.name == name)
            return enemy.weapon.cooldown;
    }
    return -1;
}

std::pair<int, int> getEnemyMovement(std::vector<Enemy> enemies, std::string name) {
    for (auto enemy : enemies) {
        if (enemy.name == name)
            return enemy.movement;
    }
    return {-1, -1};
}

float getEnemyDelay(std::vector<Enemy> enemies, std::string name) {
    for (auto enemy : enemies) {
        if (enemy.name == name)
            return enemy.delay;
    }
    return -1;
}

int getSizeOfEnemies(std::vector<Enemy> enemies) {
    return enemies.size() - 1;
}