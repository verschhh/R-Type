/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server main
*/

#include <iostream>
#include "../include/UdpServer.hpp"


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

int main(int argc, char* argv[]) {
    /**
    * @brief the main function of the server and start the server side of the project
    * @param argc the number of arguments
    * @param argv the arguments
    * @return 0 if the server is correctly launched, -1 otherwise
    */
    if ( argc != 2 ) {
      std::cout << "usage: " << argv[0] << " <port>" << std::endl;
      return -1;
    }
    int port = std::stoi(argv[1]);
    if (port <= 0 || port > 9999) {
      std::cout << "usage: " << argv[0] << " <port>" << std::endl;
      return -1;
    }
    InitServer(port);
    return 0;
}