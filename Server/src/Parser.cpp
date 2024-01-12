/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Parser
*/


#include "../include/Parser.hpp"

Parser::Parser() {}

std::unordered_map<std::string, std::string> Parser::parseMessage(const std::string& message) {
    /**
    * @brief Main function of the parser
    * @return a map of the parsed message
    */
    std::unordered_map<std::string, std::string> parsedMessage;
    std::stringstream ss(message);
    std::string item;

    while (std::getline(ss, item, '-')) {
        std::string key = extractKey(item);
        std::string value = extractValue(item);
        parsedMessage[key] = value;
    }

    return parsedMessage;
}

std::string Parser::extractKey(const std::string& pair) {
    /**
    * @brief Extract the key from a pair
    * 
    * @param pair 
    * @return std::string 
    */
    size_t pos = pair.find(':');
    return pair.substr(0, pos);
}

std::string Parser::extractValue(const std::string& pair) {
    /**
     * @brief Extract the value from a pair
     * @param pair 
     * @return std::string 
    */
    size_t pos = pair.find(':');
    return pair.substr(pos + 1);
}

