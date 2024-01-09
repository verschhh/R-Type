/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

class Parser {
/**
 * @brief Parser class
 * This class is used to parse the message received from the client
 * 
 */
    public:
        Parser();
        /**
         * @brief Construct a new Parser object
         */
        std::unordered_map<std::string, std::string> parseMessage(const std::string& message);

    private:
        std::string extractKey(const std::string& pair);
        /**
         * @brief Extract the key from a pair
         * @param pair 
         * @return std::string 
         */
        std::string extractValue(const std::string& pair);
         /**
         * @brief Extract the value from a pair
         * @param pair 
         * @return std::string 
         */
};

#endif /* !PARSER_HPP_ */
