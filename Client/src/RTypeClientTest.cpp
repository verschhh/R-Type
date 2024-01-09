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
    TestClient();
    return 0;
}