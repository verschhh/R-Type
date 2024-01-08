#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <random>

using boost::asio::ip::udp;

class udpSocket {
public:
    udpSocket(boost::asio::io_service& io_service, const std::string& sender_port)
        : socket_(io_service, udp::endpoint(udp::v4(), 0)) {
        udp::resolver resolver(io_service);
        udp::resolver::query query(udp::v4(), "127.0.0.1", sender_port);
        udp::resolver::iterator iter = resolver.resolve(query);
        endpoint_ = *iter;

        // Generate a random listener port between 10000 and 99999
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(10000, 99999);
        listener_port_ = distr(gen);

        // Send the listener port and a "Hello Server" message to the sender port
        std::string msg = std::to_string(listener_port_) + " Hello Server";
        send(msg);
    }

    void send(const std::string& msg) {
        socket_.send_to(boost::asio::buffer(msg, msg.size()), endpoint_);
    }

    void receive() {
        socket_.async_receive_from(
            boost::asio::buffer(recv_buffer_), remote_endpoint_,
            boost::bind(&udpSocket::handle_receive, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
    }

    void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred) {
        if (!error) {
            std::cout << "Received: " << std::string(recv_buffer_.begin(), recv_buffer_.begin() + bytes_transferred) << std::endl;
        }
    }

private:
    udp::socket socket_;
    udp::endpoint endpoint_;
    udp::endpoint remote_endpoint_;
    boost::array<char, 256> recv_buffer_;
    int listener_port_;
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: udp_client <sender_port>\n";
        return 1;
    }

    boost::asio::io_service io_service;
    udpSocket s(io_service, argv[1]);
    s.receive();
    io_service.run();

    return 0;
}