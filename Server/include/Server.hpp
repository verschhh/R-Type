/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <iostream>
#include <boost/asio.hpp>
#include <vector>
#include "../../Engine/Network/NLib.hpp"
#include "../include/Parser.hpp"

using boost::asio::ip::udp;

class Server {
    public:
        Server(int port, std::string ip) : server_receive(port, ip) {}
        ~Server() = default;
        int run();
        std::string GetLocalAddress();
        void ParseDataReceived(Parser parser);
        void CheckNewConnections(std::string data);
        void CheckNewDeconnections(std::string data);
        std::vector<std::string> Split(const std::string& str, const std::string& delim);
    private:
        UDPBoostNetwork::UDPReceiver server_receive;
        std::vector<UDPBoostNetwork::UDPSender> clients_send;
};

#endif /* !SERVER_HPP_ */
