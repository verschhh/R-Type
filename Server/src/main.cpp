#include <boost/asio.hpp>
#include <iostream>

boost::asio::ip::address getIp()
{
    try {
        boost::asio::io_service netService;
        boost::asio::ip::udp::resolver resolver(netService);
        boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), "google.com", "");
        boost::asio::ip::udp::resolver::iterator endpoints = resolver.resolve(query);
        boost::asio::ip::udp::endpoint ep = *endpoints;
        boost::asio::ip::udp::socket socket(netService);
        socket.connect(ep);
        boost::asio::ip::address addr = socket.local_endpoint().address();
        return addr;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void handle_connection(boost::asio::ip::tcp::socket& socket) {
    try {
        boost::asio::streambuf buffer;

        while (true) {
            boost::asio::read_until(socket, buffer, '\n');
            std::string message(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_end(buffer.data()));

            std::cout << "Received from client: " << message;

            // Process the message if needed

            // Send a response back to the client
            std::string response = "Server received: " + message;
            boost::asio::write(socket, boost::asio::buffer(response + "\n"));

            // If the message indicates the end of communication, break out of the loop
            if (message == "bye\n") {
                break;
            }

            // Clear the buffer for the next iteration
            buffer.consume(buffer.size());
        }

        // Close the socket
        socket.close();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    try {
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 12345);
        boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);
        boost::asio::ip::tcp::endpoint localEndpoint = acceptor.local_endpoint();

        std::cout << "IP Address: " << getIp() << std::endl;
        std::cout << "Port: " << localEndpoint.port() << std::endl;

        while (true) {
            boost::asio::ip::tcp::socket socket(io_service);
            acceptor.accept(socket);
            handle_connection(socket);
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}