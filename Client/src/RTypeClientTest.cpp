#include <iostream>
#include <thread>
#include <chrono>
#include "../../Engine/Network/NLib.hpp"

void TestClient() {
    // Create a client sender
    UDPBoostNetwork::UDPSender clientSender(17003, "192.168.178.26");

    // Send a "new" message to simulate a new connection
    std::cout << "Sending new connection message..." << std::endl;
    clientSender.send("new " + clientSender.get_ip() + ":" + std::to_string(clientSender.get_port()));

    // Wait for a bit to let the server process the new connection
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Send a "quit" message to simulate a disconnection
    std::cout << "Sending disconnection message..." << std::endl;
    clientSender.send("quit " + clientSender.get_ip() + ":" + std::to_string(clientSender.get_port()));
}

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

        // init Player
        // init game loop

        // Send a "quit" message to simulate a disconnection
        cSender.send("quit " + sender_ip + ":" + std::to_string(cSender.get_port()));

        r.join();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

//int main() {
//    TestClient();
//    return 0;
//}