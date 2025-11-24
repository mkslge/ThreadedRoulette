//
// Created by Mark on 11/9/25.
//
#include <iostream>

#include "../messenger.h"
#include <chrono>
#include <thread>
int main() {
    Messenger messenger(CLIENT);
    std::cout << "Sending message..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    messenger.send("JOINING");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    messenger.send("E");



    return 0;
}
