#include <boost/asio.hpp>
#include <iostream>
#include "../include/mainLoop.hpp"

// Define a handler for reading data from the server
bool handle_read(boost::asio::ip::tcp::socket& socket) {
    try {
        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, '\n');
        std::string message(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_end(buffer.data()));

        std::cout << "Received from server: " << message;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return false;
    }
    return true;
}

void send_message(boost::asio::ip::tcp::socket& socket, const std::string& message) {
    try {
        // Send a message to the server
        boost::asio::write(socket, boost::asio::buffer(message + "\n"));
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            std::cerr << "Usage: " << argv[0] << " <server_ip> <server_port>" << std::endl;
            return 1;
        }

        boost::asio::io_service io_service;
        boost::asio::ip::tcp::socket socket(io_service);
        std::string serverIP = argv[1];
        unsigned short serverPort = static_cast<unsigned short>(std::stoi(argv[2]));

        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(serverIP), serverPort);

        socket.connect(endpoint);

        std::string initialMessage = "Hello, server!\n";
        send_message(socket, "Hello, server!\n");

        while (handle_read(socket)) {
            if (!socket.is_open() || mainLoop() == -1) {
                break;
            }
        }
        socket.close();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
