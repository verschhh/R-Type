/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server main
*/

#include <iostream>
#include "../include/Server.hpp"

void Server::CheckNewConnections(std::string data)
{
    /**
    * @brief The CheckNewConnections method takes a string data as an argument. This string is expected to contain a message from a client. If the first word in the message is "new", the method interprets this as a new connection request. It then prints out the connection details and sends a "new" message to all existing clients. The new client's IP and port are extracted from the data string and used to create a new UDPSender object, which is added to the clients_send vector. Finally, the method sends a "new" message to the newly connected client for each existing client, including the IP and port of the existing client.
    * @param data 
    */
    if (Split(data, " ").front() == "new") {
        std::cout << "New connection: " << data << std::endl;
        std::cout << "Set port to: " << Split(data, " ").back() << std::endl;
        for (auto& client : clients_send) {
            client.send("new " + Split(data, " ").back());
        }
        std::string ip = Split(data, " ").back();
        std::cout << "Port " << std::stoi(Split(ip, ":").back()) << ",IP "<< Split(ip, ":").front() << std::endl;
        clients_send.push_back(UDPBoostNetwork::UDPSender(std::stoi(Split(ip, ":").back()), Split(ip, ":").front()));

        for (int i = 0; i < clients_send.size() - 1; i++) {
            clients_send.back().send("new " + clients_send[i].get_ip() + ":" + std::to_string(clients_send[i].get_port()));
        }
    }
}


void Server::CheckNewDeconnections(std::string data)
{
/**
 * @brief The CheckNewDeconnections method also takes a string data as an argument. If the first word in the message is "quit", the method interprets this as a disconnection request. It then iterates over the clients_send vector to find the client that is disconnecting, based on the IP and port in the data string. Once the disconnecting client is found, a "quit" message is sent to all remaining clients, and the disconnecting client is removed from the clients_send vector.
 * @param data 
 */
    if (Split(data, " ").front() == "quit") {
        for (int i = 0; i < clients_send.size(); i++) {
            if (clients_send[i].get_port() == std::stoi(Split(Split(data, " ").back(), ":").back()) && clients_send[i].get_ip() == Split(Split(data, " ").back(), ":").front()) {
                std::cout << "Client: " << Split(data, " ").back() << " erased" << std::endl;
                for (auto& client : clients_send) {
                    client.send("quit " + Split(data, " ").back());
                }
                clients_send.erase(clients_send.begin() + i);
                break;
            }
        }
    }

}

std::vector<std::string> Server::Split(const std::string& str, const std::string& delim)
{
/**
 * @brief Split a string
 * 
 * @param str 
 * @param token 
 * @return std::vector<std::string> 
 */
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;

    do {
        pos = str.find(delim, prev);
        if (pos == std::string::npos)
            pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty())
            tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());

    return tokens;
}

void Server::ParseDataReceived(Parser parser)
{
    const std::vector<std::string>& received_data = server_receive.GetReceivedData();

    for (const auto& data : received_data) {
        CheckNewConnections(data);
        CheckNewDeconnections(data);
        std::unordered_map<std::string, std::string> parsedMessage = parser.parseMessage(data);

    }
    server_receive.ClearReceivedData();
}

std::string Server::GetLocalAddress()
{
    /**
    * @brief the function that get the local address of the server
    * @return the local address of the server
    */
    try {
        boost::asio::io_service netService;
        boost::asio::ip::udp::resolver resolver(netService);
        boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), "google.com", "");
        boost::asio::ip::udp::resolver::iterator endpoints = resolver.resolve(query);
        boost::asio::ip::udp::endpoint ep = *endpoints;
        boost::asio::ip::udp::socket socket(netService);
        socket.connect(ep);
        boost::asio::ip::address addr = socket.local_endpoint().address();
        return addr.to_string();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return "";

}

int Server::run()
{
    /**
    * @brief Server run Function
    * @return int return code
    */
    std::thread r([&]{ server_receive.receive();});
    auto start_time = std::chrono::high_resolution_clock::now();
    Parser parser;

    while (true)
    {
        ParseDataReceived(parser);
        if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count() > 3) {
            for (auto& client : clients_send) {
                client.send("hello from the server");
            }
            start_time = std::chrono::high_resolution_clock::now();
        }
    }
    r.join();
    return 0;
}

int InitServer() {
    /**
    * @brief the function that initialize the server
    * @return 0 if the server is correctly initialized, -1 otherwise
    */

    Server server = Server(0, "0.0.0.0");
    std::string ip = server.GetLocalAddress();
    server = Server(17003, ip);
    if (server.run() == -1)
        return -1;
    server.~Server();
    return 0;
}

int main() {
    /**
    * @brief the main function of the server and start the server side of the project
    * @return 0 if the server is correctly launched, 84 otherwise
    */
    return InitServer();
}