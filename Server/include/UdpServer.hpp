#ifndef R_TYPE_SERVER_UDPSERVER_HPP
#define R_TYPE_SERVER_UDPSERVER_HPP

#include <boost/asio.hpp>
#include <iostream>

class UdpServer {
    /**
     * @brief the class that handle the server side of the project
     */
public:
    UdpServer(boost::asio::io_service& io_service, int port)
        : socket_(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)) {
        UdpReceive();
    }
    ~UdpServer();
    void UdpReceive();
    void UdpSendBack();
    boost::asio::ip::udp::endpoint getSenderEndpoint() const;
    char *getData();
    boost::asio::ip::udp::socket &getSocket();
    char *writeData(const char *data);

private:
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint sender_endpoint_;
    enum { max_length = 1024 };
    char data_[max_length];
};

#endif //R_TYPE_SERVER_UDPSERVER_HPP