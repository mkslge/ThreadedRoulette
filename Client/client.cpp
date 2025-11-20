//
// Created by Mark on 11/9/25.
//
#include <iostream>

#include "../messenger.h"

int main() {
    Messenger messenger;
    std::cout << "Sending message..." << std::endl;
    messenger.send("secret message");
    return 0;
}
