/*
** EPITECH PROJECT, 2023
** RType
** File description:
** InitServer
*/

#include <iostream>
#include "../include/InitServer.hpp"

int InitServer(int port) {
/**
 * @brief the function that initialize the server side of the project
 * @param port the port on which the server will listen
 * @return 0 if the server is correctly launched, -1 otherwise
 */
    try {
        boost::asio::io_service io_service;
        UdpServer server(io_service, port);
        io_service.run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
