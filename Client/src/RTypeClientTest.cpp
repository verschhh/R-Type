#include <iostream>
#include <thread>
#include <chrono>
#include "../../Engine/Network/NLib.hpp"


int main() {
    try {
        srand(time(NULL));
        // Create a server receiver
        UDPBoostNetwork::UDPReceiver cReceiver(0, "0.0.0.0");
        int port = (rand () % 10000) + 10000;
        std::string receiver_ip = cReceiver.getLocalIPAddress();
        std::cout << "Receiving on " << receiver_ip << ":" << port << std::endl;
        cReceiver = UDPBoostNetwork::UDPReceiver(port, receiver_ip);

        // get server ip
        std::string ip_client = "";
        std::cout << "Enter server ip: ";
        std::cin >> ip_client;

        // Create a client sender
        UDPBoostNetwork::UDPSender cSender(17003, ip_client);
        std::thread r([&] { cReceiver.receive(); });
        std::string sender_ip = cSender.get_ip();

        // Send a "new" message to simulate a new connection
        cSender.send("new " + sender_ip + ":" + std::to_string(cSender.get_port()));

        // cReceiver.receive();

        // wait for server response
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
        int on = 1;
        //print all messages received
        // init Player
        // init game loop

        for (auto& message : cReceiver.GetReceivedData()) {
            std::cout << message << std::endl;
            std::cout << "Here" << std::endl;
        }

        // Send a "quit" message to simulate a disconnection
        cSender.send("quit " + sender_ip + ":" + std::to_string(cSender.get_port()));

        for (auto& message : cReceiver.GetReceivedData()) {
            std::cout << message << std::endl;
        }

        r.join();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
