/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** UdpServer
*/

#include "../include/UdpServer.hpp"

void UdpServer::UdpReceive() {
    /**
     * @brief the function that receive the data in an asyn way from the client and send it back
     * @return void
     */
    // do asyn receiving  to buffer data_
    // [ captures ] ( params ) { body }

    socket_.async_receive_from(boost::asio::buffer(data_, max_length), sender_endpoint_,
    [this] (boost::system::error_code ec, std::size_t recvd_bytes) {
        if ( !ec && recvd_bytes > 0 ) {
            std::cout << "[" << recvd_bytes << "] " << data_ << std::endl;
            UdpSendBack();
        } else {
            UdpReceive();
        }
    });
    return;
}

void UdpServer::UdpSendBack() {
    /**
     * @brief the function that send back the data to the client
     * @return void
     */
    // do add sender information and send back
    std::string myStr = "Sender endpoint : ";
    myStr += sender_endpoint_.address().to_string().c_str();
    myStr += " port ";
    myStr += std::to_string((int)sender_endpoint_.port());
    myStr += " Message : ";
    myStr += data_;
    socket_.async_send_to(boost::asio::buffer(myStr.c_str(), myStr.length()), sender_endpoint_,
    [this] (boost::system::error_code ec, std::size_t recvd_bytes) {
        if (!ec) {
            std::string okMessage = "pute";
            std::cout << okMessage << std::endl;
            std::cout << sender_endpoint_ << std::endl;
            socket_.async_send_to(boost::asio::buffer(okMessage.c_str(), okMessage.length()), sender_endpoint_,
            [this] (boost::system::error_code ec, std::size_t recvd_bytes) {
                UdpReceive();
            });
        } else {
            UdpReceive();
        }
    });
}

boost::asio::ip::udp::endpoint UdpServer::getSenderEndpoint() const {
    /**
     * @brief a getter for the sender endpoint
     * @return the sender endpoint
     */
    return sender_endpoint_;
}

char *UdpServer::getData() {
    /**
     * @brief a getter for the data
     * @return the data
     */
    return data_;
}

char *UdpServer::writeData(const char *data) {
    /**
     * @brief a setter for the data
     * @param data the data to set
     * @return the data
     */
    memset(data_, '\0', sizeof(data_)+1);
    memcpy(data_, data, strlen(data));
    return data_;
}

boost::asio::ip::udp::socket &UdpServer::getSocket() {
    /**
     * @brief a getter for the socket
     * @return the socket
     */
    return socket_;
}

UdpServer::~UdpServer() {
}
