//
// Created by Mark on 11/9/25.
//
#include <iostream>

#include "../messenger.h"
#include <chrono>
#include <thread>
int main() {
    Messenger messenger;
    std::cout << "Sending message..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    messenger.send("secret message");

    return 0;
}
